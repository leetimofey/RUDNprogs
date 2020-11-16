#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Field
{
    int x;
    int y;
};
class FieldsClass {
private:
    vector<int> m_data;
    int m_row;
    int m_column;
public:
    Field m_empty_field;
    FieldsClass();
    FieldsClass(const FieldsClass &f);
    FieldsClass(const vector<int> &v1, int row, int column);
    vector<int> getData() const;
    inline int getRow()const{ return m_row; };
    inline int getColumn()const{ return m_column; };
    void swap(int, int, int, int);
    void doLeft();
    void doRight();
    void doTop();
    void doBottom();
    void getPosition(int data, int &startRow, int &endColumn) const;
    inline int size() const { return m_data.size(); };
    int *operator[](int i);
    const int *operator[](int i) const;
    bool operator==(const FieldsClass &) const;
    friend std::ostream &operator <<(std::ostream &out, const FieldsClass &obj);
};

const vector<int> start_fields =
        {
            1,2,3,
            8,0,4,
            7,6,5
        };
const vector<int> end_fields =
        {
                5,3,4,
                6,0,7,
                8,2,1
        };
const vector<int> test_start_fields =
        {
                1,2,3,
                4,0,5,
                6,7,8
        };
const vector<int> test_end_fields =
        {
                1,2,3,
                6,4,0,
                7,8,5
        };
void exhaustiveSearch(FieldsClass &, FieldsClass &, const std::string& s = "start");
bool contains(const vector<vector<int>>& v, const vector<int>& x);
int manhetDistance(FieldsClass &f1, const FieldsClass &f2, const std::string& s);
void empiricalMethod(FieldsClass &f1, const FieldsClass &f2, const std::string &step);

using std::vector;
using std::string;
vector<std::string> stepsVector;
vector<vector<int>> systemState;
const int MAX_DEPTH = 100;
int DEPTH = 0;
bool flag = false;
bool contains(const vector<vector<int>>& v, const vector<int>& x)
{
    return end(v) != std::find(begin(v), end(v), x);
}
void exhaustiveSearch(FieldsClass &f1,  FieldsClass &f2, const std::string &step)
{
    DEPTH++;
    if(f1 == f2)
    {
        stepsVector.emplace_back("end.");
        flag = true;
        DEPTH--;
        return;
    }
    else
    {
        if(DEPTH >= MAX_DEPTH)
        {
            if(!flag && !stepsVector.empty()) stepsVector.pop_back();
            DEPTH--;
            return;
        }
        else
        {
            if(contains(systemState, f1.getData()))
            {
                if(!flag && !stepsVector.empty()) stepsVector.pop_back();
                DEPTH--;
                return;
            }
            else
            {
                systemState.push_back(f1.getData());
                if(!flag && (step != "right") && (f1.m_empty_field.y > 0))
                {
                    f1.doLeft();
                    stepsVector.emplace_back("left");
                    exhaustiveSearch(f1,f2,"left");
                    f1.doRight();
                }
                if(!flag && (step != "left") && (f1.m_empty_field.y < (f1.getColumn() - 1)))
                {
                    f1.doRight();
                    stepsVector.emplace_back("right");
                    exhaustiveSearch(f1,f2,"right");
                    f1.doLeft();
                }
                if(!flag && (step != "bottom") && (f1.m_empty_field.x > 0))
                {
                    f1.doTop();
                    stepsVector.emplace_back("top");
                    exhaustiveSearch(f1,f2,"top");
                    f1.doBottom();
                }
                if(!flag && (step != "top") && (f1.m_empty_field.x < (f1.getRow() - 1)))
                {
                    f1.doBottom();
                    stepsVector.emplace_back("bottom");
                    exhaustiveSearch(f1,f2,"bottom");
                    f1.doTop();
                }

                if(!flag && !stepsVector.empty()) stepsVector.pop_back();
                DEPTH--;
                return;
            }
        }
    }
}


int minDistance(vector<int> &vec)
{
    int minVal = vec[0];
    for(int i =1, n = vec.size(); i<n; i++)
    {
        if(minVal>vec[i]) minVal = vec[i];
    }
    return minVal;
}
int manhetDistance(FieldsClass &f1, const FieldsClass &f2, const std::string &step)
{
    switch (step[0])
    {
        case 'l': f1.doLeft();
            break;
        case 'r': f1.doRight();
            break;
        case 't': f1.doTop();
            break;
        case 'b': f1.doBottom();
            break;
    }
    int dist = 0;
    int endRow, endColumn;
    for(int i = 0, in = f1.getRow(); i<in; i++)
    {
        for(int j = 0, jn = f1.getColumn(); j<jn; j++)
        {
            if(f2[i][j] != 0)
            {
                f2.getPosition(f1[i][j], endRow, endColumn);
                dist+= abs(i-endRow)+abs(j-endColumn);
            }
        }

    }
    switch (step[0])
    {
        case 'l': f1.doRight();
            break;
        case 'r': f1.doLeft();
            break;
        case 't': f1.doBottom();
            break;
        case 'b': f1.doTop();
            break;
    }
    return dist;
}
void empiricalMethod(FieldsClass &f1, const FieldsClass &f2, const std::string &step)
{

    if(f1 == f2)
    {
        stepsVector.emplace_back("end.");
        flag = true;
        return;
    }
    else
    {
        if(contains(systemState, f1.getData()))
        {
            if(!flag && !stepsVector.empty()) stepsVector.pop_back();
            return;
        }
        else
        {
            systemState.push_back(f1.getData());
            int LeftDist = -1, RightDist = -1, TopDist = -1, BottomDist = -1,  minDist;
            vector<int> ValuesVec;
            if(!flag && (step != "right") && (f1.m_empty_field.y > 0))
            {
                LeftDist = manhetDistance(f1,f2,"left");
                ValuesVec.push_back(LeftDist);
            }
            if(!flag && (step != "left") && (f1.m_empty_field.y < (f1.getColumn() - 1)))
            {
                RightDist = manhetDistance(f1,f2, "right");
                ValuesVec.push_back(RightDist);
            }
            if(!flag && (step != "bottom") && (f1.m_empty_field.x > 0))
            {
                TopDist = manhetDistance(f1,f2,"top");
                ValuesVec.push_back(TopDist);
            }
            if(!flag && (step != "top") && (f1.m_empty_field.x < (f1.getRow() - 1)))
            {
                BottomDist = manhetDistance(f1,f2,"bottom");
                ValuesVec.push_back(BottomDist);
            }
            minDist = minDistance(ValuesVec);
            if(!flag && (LeftDist == minDist))
            {
                f1.doLeft();
                stepsVector.emplace_back("left");
                empiricalMethod(f1,f2,"left");
                f1.doRight();
            }
            if(!flag && (RightDist == minDist))
            {
                f1.doRight();
                stepsVector.emplace_back("right");
                empiricalMethod(f1,f2,"right");
                f1.doLeft();
            }
            if(!flag && (TopDist == minDist))
            {
                f1.doTop();
                stepsVector.emplace_back("top");
                empiricalMethod(f1,f2,"top");
                f1.doBottom();
            }
            if(!flag && (BottomDist == minDist))
            {
                f1.doBottom();
                stepsVector.emplace_back("bottom");
                empiricalMethod(f1,f2,"bottom");
                f1.doTop();
            }
            if(!flag && !stepsVector.empty()) stepsVector.pop_back();
            return;
        }
    }
};

FieldsClass::FieldsClass()
{
    m_column = 0;
    m_row = 0;
}
FieldsClass::FieldsClass(const vector<int> &vec, int row, int column)
{
    m_data = vec;
    m_row = row;
    m_column = column;
    for(int i = 0, n = m_data.size(); i<n; i++)
    {
        if(m_data[i] == 0)
        {
            m_empty_field.x = i/m_row;
            m_empty_field.y = i%m_column;
        }
    }
};
FieldsClass::FieldsClass(const FieldsClass &f) {
    m_data = f.m_data;
    m_row = f.m_row;
    m_column = f.m_column;
    m_empty_field.x = f.m_empty_field.x;
    m_empty_field.y = f.m_empty_field.y;
}
vector<int> FieldsClass::getData() const
{
    return m_data;
};
void FieldsClass::swap(int r1, int c1, int r2, int c2)
{
    int index1 = r1*m_row + c1, index2 = r2*m_row + c2;
    int tmp = m_data[index1];
    m_data[index1] = m_data[index2];
    m_data[index2] = tmp;
};
void FieldsClass::doLeft()
{
    swap(m_empty_field.x, m_empty_field.y, m_empty_field.x, m_empty_field.y - 1);
    m_empty_field.y -=1;
};
void FieldsClass::doRight() {
    swap(m_empty_field.x, m_empty_field.y, m_empty_field.x, m_empty_field.y + 1);
    m_empty_field.y +=1;
}
void FieldsClass::doTop() {
    swap(m_empty_field.x, m_empty_field.y, m_empty_field.x - 1, m_empty_field.y);
    m_empty_field.x -=1;
}
void FieldsClass::doBottom() {
    swap(m_empty_field.x, m_empty_field.y, m_empty_field.x + 1, m_empty_field.y);
    m_empty_field.x +=1;
}
int *FieldsClass::operator[](int i)
{
    return &m_data[m_column*i];
};

const int *FieldsClass::operator[](int i) const
{
    return &m_data[m_column*i];
};
std::ostream &operator << (std::ostream &out, const FieldsClass &obj)
{
    for(int i = 0; i<obj.m_row; i++)
    {
        for(int j = 0; j<obj.m_column; j++)
        {
            std::cout<<obj[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

bool FieldsClass::operator==(const FieldsClass &f2) const {
    if(this->size() != f2.size()) return false;
    vector<int> v1 = this->getData();
    vector<int> v2 = f2.getData();
    for(int i = 0, n = this->size(); i<n; i++)
    {
        if(v1[i] != v2[i]) return false;
    }
    return true;
}

void FieldsClass::getPosition(int data, int &startRow, int &endColumn) const
{
    for(int i = 0; i<m_row; i++)
    {
        for(int j = 0; j<m_column; j++)
        {
            if(m_data[m_row*i+j] == data)
            {
                startRow = i;
                endColumn = j;
                return;
            }
        }
    }
};

extern vector<std::string> stepsVector;
extern vector<vector<int>> systemState;
extern bool flag;
int main() {
    FieldsClass startFields(start_fields, 3,3), endFields(end_fields, 3,3);
    FieldsClass test_startFields(test_start_fields, 3,3), test_endFields(test_end_fields, 3,3);
    cout<<"begin:"<<endl;
    cout<<startFields;
    cout<<"end:"<<endl;
    cout<<endFields;
    cout<<"empirical"<<endl;
    empiricalMethod(startFields,endFields, "start");
    cout<<"steps:"<<endl;
    for(const auto & i : stepsVector)
    {
        if(i == "end.") cout<< i;
        else cout<<i<<"->";
    }
    cout<<endl;
    cout<<"amount of unique: "<<systemState.size()<<endl;
    stepsVector.clear();
    systemState.clear();
    flag = false;
    cout<<"brute force"<<endl;
    exhaustiveSearch(startFields, endFields);
    cout<<"steps:"<<endl;
    for(const auto & i : stepsVector)
    {
        if(i == "end.") cout<< i;
        else cout<<i<<"->";
    }
    cout<<endl;
    cout<<"amount of unique: "<<systemState.size()<<endl;
    stepsVector.clear();
    systemState.clear();
    flag = false;
    return 0;
}
