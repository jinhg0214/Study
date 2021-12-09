### 1. ����� �Լ� ��ü ������ ����� ������ �����ϱ� ���� ���� �Լ� ��ü�� ���� �Լ� ��ü�� ������ ������.

> ���� �Լ� ��ü�� �Լ��� ���� ���İ� ��ȯ ������ argument_type, result_type�� ���� �Ǿ�� �ϸ�   
 ���� �Լ� ��ü�� �Լ��� ���� ���İ� ��ȯ ������ first_argument_type, second_argument_type, result_type�� ���� �Ǿ�� ��

### 2. STL�� less<T> �Լ� ��ü�� ���� ������ ����ϴ� ����� Less<T> �Լ� ��ü�� �����ϼ���. ��, Less<T>�� ����� ������ �����ؾ� �մϴ�.

    template<typename T>
    struct Less: public binary_function<T, T, T>{
        bool operator()(const T& left, const T& right) const{
            return left < right;
        }
    }

    sort(v.begin(), v.end(), Less<int>()); // ������ ȣ��

### 3. bind1st()�� bind2nd()�� �������� ������ ���� �ڵ�� ���ϼ���.

    // 50 < 100 �̹Ƿ� ��. ���� ���� 50���� ������
    cout << bind1st<less<int>>(less<int>(), 50)(100) << endl;

    // 100 < 50 �̹Ƿ� ����. ������ ���� 50���� ���� 
    cout << bind2nd<less<int>>(less<int>(), 50)(100) << endl;

### 4. not1�� not2�� �������� ������ ���� �ڵ�� ���ϼ���.

    // ���� ������ ����ü
    struct Unary:public unary_function<int, bool>{
        bool operator()(int arg) const{
            return arg < 100; // 100���� ������ ���� ��ȯ
        }
    };

    // ���� ������ ����ü
    struct Binary:public binary_function<int, int, bool> {
        bool operator()(int first, int second) const{
            return first == second; // �� ���� ������ ��
        }
    }


    cout << not1(Unary())(50) << endl;  // not1�� ���� �����ڸ� NOT 

    cout << not2(Binary())(1,1) << endl; // not2�� ���� �����ڸ� NOT �Ѵ�

### 5. ���� �ڵ带 ���� v �����̳� ��� ������ x, y�� 5�� �����ϴ� for_each() �˰����� �ϼ��Ͻÿ�.

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
 
         //for_each() �� ȣ���� ��� ������ x, y�� +5 ��ŭ �����Ѵ�.
         for_each()
     }

     struct Adder{
         void operator()(Point& pt) const{
             pt = Point(pt.GetX()+5, pt.GetY()+5); // �� ���Ҹ� 5�� ����
         }
     };

     struct Printer{
         void operator()(const Point& pt) const{
             pt.Print();
         }
     }

     for_each(v.begin(), v.end(), Adder());
     for_each(v.begin(), v.end(), Printer());