#pragma once

template <class T>
class MySet : public MyVector<T>
{
public:
    MySet(T el = NULL) : MyVector<T>(el){};
    void add_element(T el)
    {
        if ((*this).q_find(el) == -1)
        {
            (*this).MyVector<T>::add_element(el);
            return;
        }
    }
    bool is_element(T el)
    {
        if ((*this).q_find(el) == -1)
        {
            return false;
        }
        return true;
    }
    friend ostream &operator<<(ostream &out, MySet &s)
    {
        for (int i = 0; i < s.size; i++)
        {
            out << *(s.pdata + i) << endl;
        }

        return out;
    }

    MySet &operator=(MySet s)
    {
        delete[] this->pdata;
        this->size = s.size;
        this->maxsize = s.maxsize;
        this->pdata = new char *[this->maxsize];

        for (int i = 0; i < this->size; i++)
        {
            *(this->pdata + i) = *(s.pdata + i);
        }
        return (*this);
    }

    MySet &operator+=(MySet &s)
    {
        for (int i = 0; i < s.size; ++i)
        {
            if ((*this).q_find(s.pdata[i]) == -1)
            {
                (*this).add_element(s.pdata[i]);
            }
        }
        return *this;
    }
    MySet &operator-=(MySet &s)
    {
        for (int i = 0; i < s.size;)
        {
            if ((*this).q_find(s.pdata[i]) != -1)
            {
                (*this).delete_element(i);
            }
            else
            {
                ++i;
            }
        }
        return *this;
    }
    MySet &operator*=(MySet &s)
    {
        for (int i = 0; i < (*this).size;)
        {
            if (s.q_find((*this).pdata[i]) == -1)
            {
                (*this).delete_element(i);
            }
            else
            {
                ++i;
            }
        }
        return *this;
    }

    friend MySet operator+(MySet &s1, MySet &s2)
    {
        MySet<T> res;
        for (int i = 0; i < s1.size; i++)
        {
            if (res.is_element(*(s1.pdata + i)) == false)
                res.add_element(*(s1.pdata + i));
        }
        for (int i = 0; i < s2.size; i++)
        {
            if (res.is_element(*(s2.pdata + i)) == false)
                res.add_element(*(s2.pdata + i));
        }
        return res;
    }
    friend MySet operator-(MySet &s1, MySet &s2)
    {

        int n = 0;
        MySet<T> res;
        for (int i = 0; i < s1.size; i++)
        {
            for (int j = 0; j < s2.size; j++)
                if (*(s1.pdata + i) == *(s2.pdata + j))
                    n++;

            if (n == 0)
                res.add_element(*(s1.pdata + i));
            n = 0;
        }
        return res;

        // MySet<T> s3 = s1;
        // s3 -= s2;
        // return s3;
    }
    friend MySet operator*(MySet &s1, MySet &s2)
    {
        int n = 0;
        MySet<T> res;
        for (int i = 0; i < s1.size; i++)
        {
            for (int j = 0; j < s2.size; j++)
                if (*(s1.pdata + i) == *(s2.pdata + j))
                    n++;

            if (n != 0)
                res.add_element(*(s1.pdata + i));
            n = 0;
        }
        return res;
    }

    bool operator==(MySet &s)
    {
        if ((*this).size != s.size)
        {
            return false;
        }
        for (int i = 0; i < (*this).size; ++i)
        {
            if ((*this).pdata[i] != s.pdata[i])
            {
                return false;
            }
        }
        return true;
    }


private:
    int q_find(T el)
    {
        return (*this).find(el);
    }
};

template <>
bool MySet<char *>::operator==(MySet<char *> &s)
{
    if ((*this).size != s.size)
    {
        return false;
    }
    for (int i = 0; i < (*this).size; ++i)
    {
        if (strcmp((*this).pdata[i], s.pdata[i]) != 0)
        {
            return false;
        }
    }
    return true;
}