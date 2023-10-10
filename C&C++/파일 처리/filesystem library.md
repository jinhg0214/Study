- C++ 17에서 표준으로 정식 채택되었음.
- Visual Studio에서는 C++ 14를 기본으로 사용하고 있기 때문에 C++ 버전 변경 필요.
	- VS 2017 기준 프로젝트 속성 > 구성 속성 > C/C++ > 모든 옵션에서 C++ 언어 표준을 C++17으로 적용.
	- 컴파일 환경도 동일하게 설정
- GCC에서는 gcc 버전 8 이상 사용. `--std=c++17`로 버전 지정 가능 
- `<fstream>` 라이브러리가 파일 데이터의 입출력을 담당하는 라이브러리라면, `<filesystem>` 라이브러리는 파일에 관한 정보(파일 메타데이타)에 대한 접근을 도와주는 역할을 수행하며, 파일 자체를 읽는 일은 수행하지 않음.
	- 즉, 'a.txt' 파일을 찾고 싶다면 `filesystem`을, 'a.txt'를 읽고싶다면 `fstream` 라이브러리 사용



# 멤버 함수
---
### 1. 현재 경로 출력
- `current_path()` 
```C++
#include <iostream>
#include <filesystem>
 
using namespace std;
namespace fs = filesystem;
 
int main() {
    fs::path currentPath = fs::current_path();
    cout<< "Current Path: " << currentPath << endl;
    return 0;
}
```
### 2. 디렉터리 탐색, 파일/디렉터리 구분. 

- `is_regular_file()` : 파일인지
- `is_directory()` : 디렉터리인지 
- 디렉터리 순회시 `directory_iterator` 반복자 사용
- 디렉터리 내 서브 디렉터리 순회하고싶은 경우 `recursive_directory_iterator` 반복자 사용
```C++
int main() {

	fs::path directoryPath("Debug"); // 현재 프로젝트 내 Debug 폴더

	// 폴더 내 반복문은 이렇게 사용
	for (const auto& entry : fs::directory_iterator(directoryPath)) {
		if (entry.is_regular_file()) {
			cout << "File: " << entry.path() << endl;
		}
		else if (entry.is_directory()) {
			cout << "Directory: " << entry.path() << endl;
		}
	}

	return 0;
}
```

### 3. 파일 이동 및 복사
- `rename(sourceFile, destinationFile)` : 이동
- `copy(destinationFile, sourceFile)` : 복사
- `copy(from, to, fs::copy_options::recursive)` : 서브 디렉토리 내 파일도 모두 복사
```C++
const auto copyOptions = fs::copy_options::update_existing
                           | fs::copy_options::recursive
                           | fs::copy_options::directories_only
                           ;
    fs::copy("sandbox", "sandbox_copy", copyOptions);
```
- 위 처럼 여러 옵션 가능
```C++
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int main() {

	fs::path sourceFile("Debug/formatHex.exe");
	fs::path destinationFile("formatHex.exe");

	// try catch로 잡지 않으면 오류남!!! 주의 !!!!
	try {
		fs::rename(sourceFile, destinationFile); // rename으로 이동.
		cout << "File moved successfully." << endl;
	}
	catch (const fs::filesystem_error& e) {
		cout << "Failed to move file: " << e.what() << endl;
	}

	try {
		fs::copy(destinationFile, sourceFile); // copy로 복사
		cout << "File copied successfully." << endl;
	}
	catch (const std::filesystem::filesystem_error& e) {
		cout << "Failed to copy file: " << e.what() << endl;
	}

	return 0;
}
```

```cpp
// "ext" 문자열을 포함하는 파일을 모두 검색해서 벡터에 넣는 함수
#define BOOST_FILESYSTEM_VERSION 3
#define BOOST_FILESYSTEM_NO_DEPRECATED 
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

/**
 * \brief   Return the filenames of all files that have the specified extension
 *          in the specified directory and all subdirectories.
 */
std::vector<fs::path> get_all(fs::path const & root, std::string const & ext)
{
    std::vector<fs::path> paths;

    if (fs::exists(root) && fs::is_directory(root))
    {
        for (auto const & entry : fs::recursive_directory_iterator(root))
        {
            if (fs::is_regular_file(entry) && entry.path().extension() == ext)
                paths.emplace_back(entry.path().filename());
        }
    }

    return paths;
}  
```

### 4. 디렉터리 생성
- `create_directory(dirPath)` : 디렉터리 생성
```C++
#include <iostream>
#include <filesystem>
 
using namespace std;
namespace fs = filesystem;
 
int main() {
 
    fs::path dirPath("Debug2");
    if (fs::create_directory(dirPath)) {
        cout << "Directory created successfully." << endl;
    }
    else {
        cout << "Failed to create directory." << endl;
    }
 
    return 0;
}
```

### 5. 파일 존재 확인
- `fs::exists(filePath)`
```C++
#include <iostream>
#include <filesystem>
 
using namespace std;
namespace fs = filesystem;
 
int main() {
 
    fs::path filePath("path/something.txt");
    if (fs::exists(filePath)) {
        cout << "File exists." << endl;
    }
    else {
        cout << "File does not exist." << endl;
    }
 
    return 0;
}
```

ex)
- font 폴더 내 폰트 폴더를 집어넣으면 ttf폴더로 .ttf 확장자 파일을 모두 복사해주는 프로그램
```C++
#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = filesystem;

int main() {
	// font 폴더 내 .ttf 파일 싹다 모아서 
	// ttf 폴더로 옮기는 프로그램
	fs::path from("./font");
	fs::path to("./ttf");

	cout << "Current Path: " << from << endl;

	if (fs::exists(from) && fs::is_directory(from)) {
		// 디렉터리 내 서브 디렉터리까지 모두 순회하는 반복자는 
		// fs::recursive_directory_iterator 이용
		for (const auto& entry : fs::recursive_directory_iterator(from)) {
			if (fs::is_regular_file(entry) && entry.path().extension() == ".ttf") {
				
				cout << entry.path().filename() << " : ";
				try {
					fs::copy(entry.path(), to, fs::copy_options::update_existing);
					cout << "File moved successfully." << endl;
				}
				catch (const fs::filesystem_error& e) {
					cout << "Failed to move file: " << e.what() << endl;
				}
			}
		}
	}
}
```