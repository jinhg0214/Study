### 1. 사용자 함수 객체 구현시 어댑터 적용이 가능하기 위한 단항 함수 객체와 이항 함수 객체의 조건을 쓰세요.

> 단항 함수 객체는 함수의 인자 형식과 반환 형식인 argument_type, result_type이 정의 되어야 하며   
 이항 함수 객체는 함수의 인자 형식과 반환 형식인 first_argument_type, second_argument_type, result_type이 정의 되어야 함

### 2. STL의 less<T> 함수 객체와 같은 동작을 사용하는 사용자 Less<T> 함수 객체를 구현하세요. 단, Less<T>는 어댑터 적용이 가능해야 합니다.

    template<typename T>
    struct Less: public binary_function<T, T, T>{
        bool operator()(const T& left, const T& right) const{
            return left < right;
        }
    }

    sort(v.begin(), v.end(), Less<int>()); // 등으로 호출

### 3. bind1st()와 bind2nd()의 차이점을 간단한 예제 코드로 비교하세요.

    // 50 < 100 이므로 참. 왼쪽 항을 50으로 고정함
    cout << bind1st<less<int>>(less<int>(), 50)(100) << endl;

    // 100 < 50 이므로 거짓. 오른쪽 항을 50으록 조정 
    cout << bind2nd<less<int>>(less<int>(), 50)(100) << endl;

### 4. not1과 not2의 차이점을 간단한 예제 코드로 비교하세요.

    // 단항 조건자 구조체
    struct Unary:public unary_function<int, bool>{
        bool operator()(int arg) const{
            return arg < 100; // 100보다 작으면 참을 반환
        }
    };

    // 이항 조건자 구조체
    struct Binary:public binary_function<int, int, bool> {
        bool operator()(int first, int second) const{
            return first == second; // 두 항이 같으면 참
        }
    }


    cout << not1(Unary())(50) << endl;  // not1은 단항 조건자를 NOT 

    cout << not2(Binary())(1,1) << endl; // not2은 이항 조건자를 NOT 한다

### 5. 다음 코드를 보고 v 컨테이너 모든 원소의 x, y를 5씩 증가하는 for_each() 알고리즘을 완성하시오.

     class Point{
         int x;
         int y;
     public:
         explicit Point(int _x=0, int _y=0):x(_x), y(_y){}
         void Print() const {cout << x << "," << y << endl;}
         int GetX() const {return x;}
         int GetY() const {return y;}
     };
 
     int main(){
         vector<Point> v;
         v.push_back(Point(1,1));
         v.push_back(Point(2,2));
         v.push_back(Point(3,3));
         v.push_back(Point(4,4));
         v.push_back(Point(5,5));
 
         //for_each() 를 호출해 모든 원소의 x, y를 +5 만큼 증가한다.
         for_each()
     }

     struct Adder{
         void operator()(Point& pt) const{
             pt = Point(pt.GetX()+5, pt.GetY()+5); // 각 원소를 5씩 증가
         }
     };

     struct Printer{
         void operator()(const Point& pt) const{
             pt.Print();
         }
     }

     for_each(v.begin(), v.end(), Adder());
     for_each(v.begin(), v.end(), Printer());