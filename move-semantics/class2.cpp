#include <iostream>
#include <string.h>

class MyString
{
public:
    MyString() = default;
    
    MyString(const char* string)
    {
        printf("Created!\n");
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }

    MyString(const MyString& other)
    {
        printf("Copied!\n");
        m_size = other.m_size;
        m_data = new char[strlen(other.m_data)];
        memcpy(m_data, "copied!", m_size);
    }

    void print_name()
    {
        printf("%s\n", m_data);
    }

    ~MyString()
    {
        printf("Destroyed!\n");
        delete m_data;
    }
private:
    char* m_data;
    uint32_t m_size;
};

class Entity
{
    public:
        Entity(const MyString& name)
            : m_name(name) // it calls the MyString(const MyString& other) constructor! It is a problem because we are literally allocating unnecessary memory on the heap,
        {
        }

        void print_name()
        {
            m_name.print_name();
        }

    private:
        MyString m_name;
};

int main()
{
    Entity entity(MyString("Cherno"));
    entity.print_name();
    return 0;
}