
#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <map>
#include <vector>
#include <stack>
#include <iostream>


ft::map<int,char>	sample_map()
{
    ft::map<int,char>	map;

    map.insert( ft::make_pair( -233, 's' ) );
    map.insert( ft::make_pair(  23, 'b' ) );
    map.insert( ft::make_pair(  12, 'c' ) );
    map.insert( ft::make_pair(  -1, 'd' ) );
    map.insert( ft::make_pair(  184, 'e' ) );

    return ( map );
}

std::map<int,char>	sample_map2()
{
    std::map<int,char>	map;

    map.insert( std::make_pair( -233, 's' ) );
    map.insert( std::make_pair(  23, 'b' ) );
    map.insert( std::make_pair(  12, 'c' ) );
    map.insert( std::make_pair(  -1, 'd' ) );
    map.insert( std::make_pair(  184, 'e' ) );

    return ( map );
}



void test_vector()
{
    // ////////////////////////////////////         CONSTRUCTORS          ////////////////////////////
    std::cout << "       ---------------- CONSTRUCTORS --------------    " << std::endl;

    {
        // /////////////////////////           Testing std::vector Constructors              //////////////////////////
        std::cout << std::endl;
        std::cout << " STD::VECTOR       TESTS  " << std::endl;

        {
            std::vector<int> first;
            std::vector<int> second(7, 450);
            std::vector<int> third(second.begin(), second.end());
            std::vector<int> fourth(third);

            int myints[] = {16, 2, 77, 29};
            std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

            std::cout << "The contents of fifth are : ";
            for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
                std::cout << ' ' << *it;

            std::cout << std::endl;
            std::cout << "std::vector SIZE :       " << fourth.size() << std::endl;
            std::cout << "std::vector CAPACITY :       " << fourth.capacity() << std::endl;
        }

        // /////////////////////////           Testing ft::vector Constructors              //////////////////////////
        std::cout << std::endl;

        std::cout << " FT::VECTOR       TESTS  " << std::endl;

        {
            ft::vector<int> first;
            ft::vector<int> second(7, 450);
            ft::vector<int> third(second.begin(), second.end());
            ft::vector<int> fourth(third);

            int myints[] = {16, 2, 77, 29};
            ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

            std::cout << "The contents of fifth are:";
            for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
                std::cout << ' ' << *it;

            std::cout << std::endl;
            std::cout << "ft::vector SIZE :       " << fourth.size() << std::endl;
            std::cout << "std::vector CAPACITY :       " << fourth.capacity() << std::endl;
        }
    }

    // ////////////////////////////////////         operator=          ////////////////////////////
    std::cout << "        ---------------  OPERATOR=  -------------    " << std::endl;
    {
        // /////////////////////////           Testing std::vector operator=              //////////////////////////
        std::cout << std::endl;

        std::cout << " STD::VECTOR       TESTS  " << std::endl;

        {
            std::vector<int> foo(3, 0);
            std::vector<int> bar(5, 0);

            bar = foo;
            foo = std::vector<int>();

            std::cout << "Size of foo: " << int(foo.size()) << std::endl;
            std::cout << "Size of bar: " << int(bar.size()) << std::endl;
        }

        std::cout << std::endl;

        // /////////////////////////           Testing ft::vector operator=              //////////////////////////
        std::cout << std::endl;

        std::cout << " FT::VECTOR       TESTS  " << std::endl;

        {
            ft::vector<int> foo(3, 0);
            ft::vector<int> bar(5, 0);

            bar = foo;
            foo = ft::vector<int>();

            std::cout << "Size of foo: " << int(foo.size()) << std::endl;
            std::cout << "Size of bar: " << int(bar.size()) << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "    ------------------ CAPACITY -------------------   " << std::endl;

    {
        std::cout << std::endl;

        std::cout << " STD::VECTOR       TESTS  " << std::endl;

        {
            std::vector<int> myvector;

            // set some content in the vector:
            for (int i = 0; i < 100; i++) myvector.push_back(i);

            std::cout << "size: " << (int) myvector.size() << '\n';
            std::cout << "capacity: " << (int) myvector.capacity() << '\n';
            std::cout << "max_size: " << (int) myvector.max_size() << '\n';
        }

        std::cout << std::endl;

        std::cout << " FT::VECTOR       TESTS  " << std::endl;

        {
            ft::vector<int> myvector;

            // set some content in the vector:
            for (int i = 0; i < 100; i++) myvector.push_back(i);

            std::cout << "size: " << (int) myvector.size() << '\n';
            std::cout << "capacity: " << (int) myvector.capacity() << '\n';
            std::cout << "max_size: " << (int) myvector.max_size() << '\n';
        }
        std::cout << std::endl;
    }

    std::cout << "    --------------------- RESIZE --------------------    " << std::endl;

    {
        std::cout << std::endl;

        std::cout << " STD::VECTOR       TESTS  " << std::endl;

        {
            std::vector<int> myvector;

            // set some initial content:
            for (int i = 1; i < 10; i++) myvector.push_back(i);

            myvector.resize(5);
            myvector.resize(8, 100);
            myvector.resize(12);

            std::cout << "myvector contains:";
            for (int i = 0; i < myvector.size(); i++)
                std::cout << ' ' << myvector[i];
            std::cout << std::endl;
        }

        std::cout << std::endl;

        std::cout << " FT::VECTOR       TESTS  " << std::endl;

        {
            ft::vector<int> myvector;

            // set some initial content:
            for (int i = 1; i < 10; i++) myvector.push_back(i);

            myvector.resize(5);
            myvector.resize(8, 100);
            myvector.resize(12);

            std::cout << "myvector contains:";
            for (int i = 0; i < myvector.size(); i++)
                std::cout << ' ' << myvector[i];
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "            -------------------- RESERVE --------------------   " << std::endl;

    {
        std::cout << std::endl;

        std::cout << "  STD::VECTOR    TESTS " << std::endl;

        {
            std::vector<int>::size_type sz;

            std::vector<int> foo;
            sz = foo.capacity();
            std::cout << "making foo grow:\n";
            for (int i=0; i<100; ++i) {
                foo.push_back(i);
                if (sz!=foo.capacity()) {
                    sz = foo.capacity();
                    std::cout << "capacity changed: " << sz << '\n';
                }
            }

            std::vector<int> bar;
            sz = bar.capacity();
            bar.reserve(100);   // this is the only difference with foo above
            std::cout << "making bar grow:\n";
            for (int i=0; i<100; ++i) {
                bar.push_back(i);
                if (sz!=bar.capacity()) {
                    sz = bar.capacity();
                    std::cout << "capacity changed: " << sz << '\n';
                }
            }
        }
            std::cout << std::endl;

            std::cout << " FT::VECTOR       TESTS  " << std::endl;

        {
            ft::vector<int>::size_type sz;

            ft::vector<int> foo;
            sz = foo.capacity();
            std::cout << "making foo grow:\n";
            for (int i=0; i<100; ++i) {
                foo.push_back(i);
                if (sz!=foo.capacity()) {
                    sz = foo.capacity();
                    std::cout << "capacity changed: " << sz << '\n';
                }
            }

            ft::vector<int> bar;
            sz = bar.capacity();
            bar.reserve(100);   // this is the only difference with foo above
            std::cout << "making bar grow:\n";
            for (int i=0; i<100; ++i) {
                bar.push_back(i);
                if (sz!=bar.capacity()) {
                    sz = bar.capacity();
                    std::cout << "capacity changed: " << sz << '\n';
                }
            }
        }
        std::cout << std::endl;

        std::cout << " ------------------ operator[] ----------------  " << std::endl;

        {
            std::cout << std::endl;

            std::cout << "  STD::VECTOR    TESTS " << std::endl;
            {
                std::vector<int> myvector(10);   // 10 zero-initialized elements

                std::vector<int>::size_type sz = myvector.size();

                // assign some values:
                for (unsigned i = 0; i < sz; i++) myvector[i] = i;

                // reverse vector using operator[]:
                for (unsigned i = 0; i < sz / 2; i++) {
                    int temp;
                    temp = myvector[sz - 1 - i];
                    myvector[sz - 1 - i] = myvector[i];
                    myvector[i] = temp;
                }

                std::cout << "myvector contains:";
                for (unsigned i = 0; i < sz; i++)
                    std::cout << ' ' << myvector[i];
                std::cout << std::endl;
            }

            std::cout << std::endl;

            std::cout << " FT::VECTOR       TESTS  " << std::endl;

            {
                ft::vector<int> myvector(10);   // 10 zero-initialized elements

                ft::vector<int>::size_type sz = myvector.size();

                // assign some values:
                for (unsigned i = 0; i < sz; i++) myvector[i] = i;

                // reverse vector using operator[]:
                for (unsigned i = 0; i < sz / 2; i++) {
                    int temp;
                    temp = myvector[sz - 1 - i];
                    myvector[sz - 1 - i] = myvector[i];
                    myvector[i] = temp;
                }

                std::cout << "myvector contains:";
                for (unsigned i = 0; i < sz; i++)
                    std::cout << ' ' << myvector[i];
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
        std::cout << " -------------  assign -------------------  " << std::endl;

        {
            std::cout << std::endl;

            std::cout << "  STD::VECTOR    TESTS " << std::endl;
            {
                std::vector<int> first;
                std::vector<int> second;
                std::vector<int> third;

                first.assign (7,100);

                std::vector<int>::iterator it;
                it=first.begin()+1;

                second.assign (it,first.end()-1);

                int myints[] = {1776,7,4};
                third.assign (myints,myints+3);

                std::cout << "Size of first: " << int (first.size()) << '\n';
                std::cout << "Size of second: " << int (second.size()) << '\n';
                std::cout << "Size of third: " << int (third.size()) << '\n';

                std::cout << "Capacity of first: " << int (first.capacity()) << '\n';
                std::cout << "Capacity of second: " << int (second.capacity()) << '\n';
                std::cout << "Capacity of third: " << int (third.capacity()) << '\n';
            }
            std::cout << std::endl;

            std::cout << " FT::VECTOR       TESTS  " << std::endl;
            {
                ft::vector<int> first;
                ft::vector<int> second;
                ft::vector<int> third;

                first.assign (7,100);

                ft::vector<int>::iterator it;
                it=first.begin()+1;

                second.assign (it,first.end()-1);

                int myints[] = {1776,7,4};
                third.assign (myints,myints+3);

                std::cout << "Size of first: " << int (first.size()) << '\n';
                std::cout << "Size of second: " << int (second.size()) << '\n';
                std::cout << "Size of third: " << int (third.size()) << '\n';

                std::cout << "Capacity of first: " << int (first.capacity()) << '\n';
                std::cout << "Capacity of second: " << int (second.capacity()) << '\n';
                std::cout << "Capacity of third: " << int (third.capacity()) << '\n';
            }
        }
        std::cout << std::endl;
        std::cout << " --------------  insert  -----------------  " << std::endl;

        {
            std::cout << std::endl;

            std::cout << "  STD::VECTOR    TESTS " << std::endl;
            {
                std::vector<int> myvector (3,100);
                std::vector<int>::iterator it;

                it = myvector.begin();
                it = myvector.insert ( it , 200 );

                myvector.insert (it,2,300);

                it = myvector.begin();

                std::vector<int> anothervector (2,400);
                myvector.insert (it+2,anothervector.begin(),anothervector.end());

                int myarray [] = { 501,502,503 };
                myvector.insert (myvector.begin(), myarray, myarray+3);

                std::cout << "myvector contains:";
                for (it=myvector.begin(); it<myvector.end(); it++)
                    std::cout << ' ' << *it;
                std::cout << std::endl;

                std::cout << "std::vector CAPACITY :   " << myvector.capacity() << std::endl;

            }
            std::cout << std::endl;

            std::cout << " FT::VECTOR       TESTS  " << std::endl;
            {
                ft::vector<int> myvector (3,100);
                ft::vector<int>::iterator it;

                it = myvector.begin();
                it = myvector.insert ( it , 200 );

                myvector.insert (it,2,300);

                // "it" no longer valid, get a new one:
                it = myvector.begin();

                ft::vector<int> anothervector (2,400);
                myvector.insert (it+2,anothervector.begin(),anothervector.end());

                int myarray [] = { 501,502,503 };
                myvector.insert (myvector.begin(), myarray, myarray+3);

                std::cout << "myvector contains:";
                for (it=myvector.begin(); it<myvector.end(); it++)
                    std::cout << ' ' << *it;
                std::cout << std::endl;

                std::cout << "ft_vector CAPACITY :   " << myvector.capacity() << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << " --------------- erase ------------------  " << std::endl;
        {
            std::cout << std::endl;

            std::cout << "  STD::VECTOR    TESTS " << std::endl;
            {
                std::vector<int> myvector;

                for (int i=7; i<=33; i++) myvector.push_back(i);

                // erase the 6th element
                myvector.erase (myvector.begin()+5);

                // erase the first 3 elements:
                myvector.erase (myvector.begin(),myvector.begin()+3);

                std::cout << "myvector contains:";
                for (unsigned i=0; i<myvector.size(); ++i)
                    std::cout << ' ' << myvector[i];
                std::cout << std::endl;

                std::cout << "std::vector CAPACITY :   " << myvector.capacity() << std::endl;
            }

            std::cout << std::endl;

            std::cout << " FT::VECTOR       TESTS  " << std::endl;
            {
                ft::vector<int> myvector;

                for (int i=7; i<=33; i++) myvector.push_back(i);

                // erase the 6th element
                myvector.erase (myvector.begin()+5);

                // erase the first 3 elements:
                myvector.erase (myvector.begin(),myvector.begin()+3);

                std::cout << "myvector contains:";
                for (unsigned i=0; i<myvector.size(); ++i)
                    std::cout << ' ' << myvector[i];
                std::cout << std::endl;

                std::cout << "ft_vector CAPACITY :   " << myvector.capacity() << std::endl;
            }
        }
        std::cout << std::endl;

        std::cout << " ----------------- swap ---------------------  " << std::endl;
        {
            std::cout << std::endl;

            std::cout << "  STD::VECTOR    TESTS " << std::endl;
            {
                std::vector<int> foo (3,10);
                std::vector<int> bar (2,800);

                foo.swap(bar);

                std::cout << "foo contains:";
                for (unsigned i=0; i<foo.size(); i++)
                    std::cout << ' ' << foo[i];
                std::cout << '\n';

                std::cout << "bar contains:";
                for (unsigned i=0; i<bar.size(); i++)
                    std::cout << ' ' << bar[i];
                std::cout << std::endl;
            }

            std::cout << std::endl;

            std::cout << " FT::VECTOR       TESTS  " << std::endl;
            {
                ft::vector<int> foo (3,10);
                ft::vector<int> bar (2,800);

                foo.swap(bar);

                std::cout << "foo contains:";
                for (unsigned i=0; i<foo.size(); i++)
                    std::cout << ' ' << foo[i];
                std::cout << '\n';

                std::cout << "bar contains:";
                for (unsigned i=0; i<bar.size(); i++)
                    std::cout << ' ' << bar[i];
                std::cout << std::endl;
            }
        }
    }
}
    // ////////////////////////////////////     MAP TESTSSSSS     ///////////////////////////////////


    bool fncomp (char lhs, char rhs) {return lhs<rhs;}

    struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    { return lhs < rhs; }
    };

void map_test()
{
    std::cout << std::endl;

    std::cout << "  **************************************************  MAP TESTS  *********************************************  " << std::endl;

    std::cout << std::endl;

    std::cout << "------------ Constructors ---------------  " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {

            std::map<char,int> first;

            first['a']=10;
            first['b']=30;
            first['c']=50;
            first['d']=70;

            std::map<char,int> second (first.begin(),first.end());

            std::map<char,int> third (second);

            std::map<char,int,classcomp> fourth;                 // class as Compare

            bool(*fn_pt)(char,char) = fncomp;
            std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<char,int> first;

            first['a']=10;
            first['b']=30;
            first['c']=50;
            first['d']=70;

            ft::map<char,int> second (first.begin(),first.end());

            ft::map<char,int> third (second);

            ft::map<char,int,classcomp> fourth;                 // class as Compare

            bool(*fn_pt)(char,char) = fncomp;
            ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
        }
    }
    std::cout << std::endl;

    std::cout << " -----------------  operator=  -------------------------  " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<char,int> first;
            std::map<char,int> second;

            first['x']=8;
            first['y']=16;
            first['z']=32;

            second=first;                // second now contains 3 ints
            first=std::map<char,int>();  // and first is now empty

            std::cout << "Size of first: " << first.size() << '\n';
            std::cout << "Size of second: " << second.size() << '\n';
        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<char,int> first;
            ft::map<char,int> second;

            first['x'] = 8;
            first['y'] = 16;
            first['z'] = 32;

            second = first;                // second now contains 3 ints
            first = ft::map<char,int>();  // and first is now empty

            std::cout << "Size of first: " << first.size() << '\n';
            std::cout << "Size of second: " << second.size() << '\n';
        }
    }
    std::cout << std::endl;

    std::cout << " --------------- operator[] ------------------- " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<char,std::string> mymap;

            mymap['a'] = "aqds";
            mymap['b'] = "element";
            mymap['c'] = mymap['b'];

            std::cout << "mymap['a'] is " << mymap['a'] << '\n';
            std::cout << "mymap['b'] is " << mymap['b'] << '\n';
            std::cout << "mymap['c'] is " << mymap['c'] << '\n';
            std::cout << "mymap['d'] is " << mymap['d'] << '\n';

            std::cout << "mymap now contains " << mymap.size() << " elements.\n";
        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<char,std::string> mymap;

            mymap['a'] = "aqds";
            mymap['b'] = "element";
            mymap['c'] = mymap['b'];

            std::cout << "['a'] is " << mymap['a'] << '\n';
            std::cout << "['b'] is " << mymap['b'] << '\n';
            std::cout << "['c'] is " << mymap['c'] << '\n';
            std::cout << "['d'] is " << mymap['d'] << '\n';

            std::cout << "mymap contains " << mymap.size() << " elements.\n";
        }
    }
    std::cout << std::endl;

    std::cout << " -------------------------  insert  --------------------------------- " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<char,int> mymap;

            mymap.insert ( std::pair<char,int>('a',100) );
            mymap.insert ( std::pair<char,int>('z',200) );

            std::pair<std::map<char,int>::iterator,bool> ret;
            ret = mymap.insert ( std::pair<char,int>('z',500) );
            if (ret.second==false) {
                std::cout << "element 'z' already existed";
                std::cout << " with a value of " << ret.first->second << '\n';
            }

            std::map<char,int>::iterator it = mymap.begin();
            mymap.insert (it, std::pair<char,int>('b',300));
            mymap.insert (it, std::pair<char,int>('c',400));

            std::map<char,int> anothermap;
            anothermap.insert(mymap.begin(),mymap.find('c'));

            // showing contents:
            std::cout << "mymap contains:\n";
            for (it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            std::cout << "anothermap contains:\n";
            for (it=anothermap.begin(); it!=anothermap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<char,int> mymap;

            mymap.insert ( ft::pair<char,int>('a',100) );
            mymap.insert ( ft::pair<char,int>('z',200) );

            ft::pair<ft::map<char,int>::iterator,bool> ret;
            ret = mymap.insert ( ft::pair<char,int>('z',500) );
            if (ret.second == false) {
                std::cout << "element 'z' already existed";
                std::cout << " with a value of " << ret.first->second << '\n';
            }

            ft::map<char,int>::iterator it = mymap.begin();
            mymap.insert (it, ft::pair<char,int>('b',300));
            mymap.insert (it, ft::pair<char,int>('c',400));

            ft::map<char,int> anothermap;
            anothermap.insert(mymap.begin(),mymap.find('c'));

            // showing contents:
            std::cout << "mymap contains:\n";
            for (it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            std::cout << "anothermap contains:\n";
            for (it = anothermap.begin(); it != anothermap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
    }
    std::cout << std::endl;

    std::cout << " ----------------------  erase  -----------------------  " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<char,int> mymap;
            std::map<char,int>::iterator it;

            // insert some values:
            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;
            mymap['d']=40;
            mymap['e']=50;
            mymap['f']=60;

            std::cout << "map Content :  ";
            for (std::map<char,int>::iterator it1 = mymap.begin(); it1 != mymap.end(); it1++)
                std::cout << "  " << it1->first;
            std::cout << std::endl;
            it=mymap.find('b');
            mymap.erase (it);                   // erasing by iterator

            mymap.erase ('c');                  // erasing by key

            it=mymap.find ('e');
            mymap.erase ( it, mymap.end() );    // erasing by range

            // show content:
            for (it = mymap.begin(); it != mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<char,int> mymap;
            ft::map<char,int>::iterator it;

            // insert some values:
            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;
            mymap['d']=40;
            mymap['e']=50;
            mymap['f']=60;

            std::cout << "map Content :  ";
            for (ft::map<char,int>::iterator it1 = mymap.begin(); it1 != mymap.end(); it1++)
                std::cout << "  " << it1->first;
            std::cout << std::endl;

            it=mymap.find('b');
            mymap.erase (it);                   // erasing by iterator

            mymap.erase ('c');                  // erasing by key

            it=mymap.find ('e');
            mymap.erase ( it, mymap.end() );    // erasing by range

            // show content:
            for (it = mymap.begin(); it != mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
    }
    std::cout << std::endl;

    std::cout << " ------------------  swap  ----------------------  " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<char,int> foo,bar;

            foo['x']=100;
            foo['y']=200;

            bar['a']=11;
            bar['b']=22;
            bar['c']=33;

            foo.swap(bar);

            std::cout << "foo contains:\n";
            for (std::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            std::cout << "bar contains:\n";
            for (std::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<char,int> foo,bar;

            foo['x']=100;
            foo['y']=200;

            bar['a']=11;
            bar['b']=22;
            bar['c']=33;

            foo.swap(bar);

            std::cout << "foo contains:\n";
            for (ft::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            std::cout << "bar contains:\n";
            for (ft::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
    }
    std::cout << std::endl;

    std::cout << " ------------------  lower_bound  -----------------  " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<char,int> mymap;
            std::map<char,int>::iterator itlow,itup;

            mymap['a']=20;
            mymap['b']=40;
            mymap['c']=60;
            mymap['d']=80;
            mymap['e']=100;

            itlow=mymap.lower_bound ('b');
            itup=mymap.upper_bound ('d');

            mymap.erase(itlow,itup);

            // print content:
            for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<char,int> mymap;
            ft::map<char,int>::iterator itlow,itup;

            mymap['a'] = 20;
            mymap['b'] = 40;
            mymap['c'] = 60;
            mymap['d'] = 80;
            mymap['e'] = 100;

            itlow=mymap.lower_bound ('b');
            itup=mymap.upper_bound ('d');

            mymap.erase(itlow,itup);

            // print content:
            for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
    }
    std::cout << std::endl;

    std::cout << " -----------------------  iterators  ------------------------------  " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<int,char>	map = sample_map();

            std::cout << "map:\t";
            ft::map<int,char>::const_iterator cit = map.begin();
            ft::map<int,char>::iterator ite = map.end();
            for ( ; cit != ite; cit++ )
                std::cout << '\t' << cit->first << ' ' << cit->second;
            std::cout << std::endl;

            std::cout << "map reversed:";
            ft::map<int,char>::const_reverse_iterator crite = map.rend();
            for ( ft::map<int,char>::reverse_iterator rit = map.rbegin(); rit != crite; ++rit )
                std::cout << '\t' << rit->first << ' ' << rit->second;
            std::cout << std::endl;

            std::cout << "--------------------" << std::endl << std::endl;

        }
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<int,char>	map = sample_map2();

            std::cout << "map:\t";
            std::map<int,char>::const_iterator cit = map.begin();
            std::map<int,char>::iterator ite = map.end();
            for ( ; cit != ite; cit++ )
                std::cout << '\t' << cit->first << ' ' << cit->second;
            std::cout << std::endl;

            std::cout << "map reversed:";
            std::map<int,char>::const_reverse_iterator crite = map.rend();
            for ( std::map<int,char>::reverse_iterator rit = map.rbegin(); rit != crite; ++rit )
                std::cout << '\t' << rit->first << ' ' << rit->second;
            std::cout << std::endl;

            std::cout << "--------------------" << std::endl << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << " -----------------  capacity  ---------------------- " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<int,char>	map = sample_map2();

            std::cout << "map.size() = " << map.size() << std::endl;
            std::cout << "map.empty() = " << map.empty() << std::endl;
            std::cout << "----------" << std::endl;

            std::map<int,char>	map2;
            std::cout << "-> map2 default constructed" << std::endl;
            std::cout << "map2.empty() = " << map2.empty() << std::endl;

            std::cout << "--------------------" << std::endl << std::endl;

        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<int,char>	map = sample_map();

            std::cout << "map.size() = " << map.size() << std::endl;
            std::cout << "map.empty() = " << map.empty() << std::endl;
            std::cout << "----------" << std::endl;

            ft::map<int,char>	map2;
            std::cout << "-> map2 default constructed" << std::endl;
            std::cout << "map2.empty() = " << map2.empty() << std::endl;

            std::cout << "--------------------" << std::endl << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << " --------------  Observers  --------------------- " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "  STD::MAP    TESTS " << std::endl;
        {
            std::map<char,int>	map;
            std::map<char,int>::key_compare	comp = map.key_comp();

            map['a'] = 100;
            map['b'] = 200;
            map['c'] = 300;

            char	highest = map.rbegin()->first;
            std::map<char,int>::iterator	it = map.begin();
            std::cout << "map contains:" << std::endl;
            do
            {
                std::cout << it->first << " => " << it->second << std::endl;
            } while ( comp( (*it++).first, highest ) );
            std::cout << std::endl;


            std::map<char,int>	map2;

            map2['x'] = 1001;
            map2['y'] = 2002;
            map2['z'] = 3003;

            std::pair<char,int>	highest2 = *map2.rbegin();
            std::map<char,int>::iterator	it2 = map2.begin();
            std::cout << "map2 contains:" << std::endl;
            do
            {
                std::cout << it2->first << " => " << it2->second << std::endl;
            } while ( map2.value_comp()( *it2++, highest2 ) );

            std::cout << "--------------------" << std::endl << std::endl;

        }
        std::cout << std::endl;

        std::cout << "  FT::MAP    TESTS " << std::endl;
        {
            ft::map<char,int>	map;
            ft::map<char,int>::key_compare	comp = map.key_comp();

            map['a'] = 100;
            map['b'] = 200;
            map['c'] = 300;

            char	highest = map.rbegin()->first;
            ft::map<char,int>::iterator	it = map.begin();
            std::cout << "map contains:" << std::endl;
            do
            {
                std::cout << it->first << " => " << it->second << std::endl;
            } while ( comp( (*it++).first, highest ) );
            std::cout << std::endl;


            ft::map<char,int>	map2;

            map2['x'] = 1001;
            map2['y'] = 2002;
            map2['z'] = 3003;

            ft::pair<char,int>	highest2 = *map2.rbegin();
            ft::map<char,int>::iterator	it2 = map2.begin();
            std::cout << "map2 contains:" << std::endl;
            do
            {
                std::cout << it2->first << " => " << it2->second << std::endl;
            } while ( map2.value_comp()( *it2++, highest2 ) );

            std::cout << "--------------------" << std::endl << std::endl;
        }
    }
}

void stack_test()
{
    std::cout << std::endl;

    std::cout << " ****************************  STACK TESTS  ******************************** " << std::endl;
    {
        std::cout << std::endl;

        std::cout << "         STD::STACK    TESTS            " << std::endl;

        {
            std::stack< int, std::vector<int> >	stack;

            std::cout << "-> stack" << std::endl;
            std::cout << "stack size = " << stack.size() << std::endl;
            std::cout << "stack empty = " << stack.empty() << std::endl;
            std::cout << "stack.push(1)" << std::endl;
            stack.push(1);
            std::cout << "stack.push(2)" << std::endl;
            stack.push(2);
            std::cout << "stack top = " << stack.top() << std::endl;
            std::cout << "stack.pop()" << std::endl;
            stack.pop();

            std::stack< int, std::vector<int> >	stack2(stack);
            std::cout << "-> stack2" << std::endl;
            std::cout << "stack2 = stack" << std::endl;
            stack2 = stack;
            std::cout << std::boolalpha;
            std::cout << "stack == stack2: " << (stack == stack2) << std::endl;
            std::cout << "stack < stack2: " << (stack < stack2) << std::endl;
            std::cout << "stack2.push(3)" << std::endl;
            stack2.push(3);
            std::cout << "stack2 == stack2: " << (stack == stack2) << std::endl;
            std::cout << "stack2 < stack2: " << (stack < stack2) << std::endl;
            std::cout << "stack size = " << stack.size() << std::endl;
            std::cout << "stack empty = " << stack.empty() << std::endl;
            std::cout << "stack top = " << stack.top() << std::endl;
            std::cout << "stack2 size = " << stack2.size() << std::endl;
            std::cout << "stack2 top = " << stack2.top() << std::endl;
        }

        std::cout << std::endl;

        std::cout << "         FT::STACK    TESTS            " << std::endl;
        {
            ft::stack< int, ft::vector<int> >	stack;

            std::cout << "-> stack" << std::endl;
            std::cout << "stack size = " << stack.size() << std::endl;
            std::cout << "stack empty = " << stack.empty() << std::endl;
            std::cout << "stack.push(1)" << std::endl;
            stack.push(1);
            std::cout << "stack.push(2)" << std::endl;
            stack.push(2);
            std::cout << "stack top = " << stack.top() << std::endl;
            std::cout << "stack.pop()" << std::endl;
            stack.pop();

            ft::stack< int, ft::vector<int> >	stack2(stack);
            std::cout << "-> stack2" << std::endl;
            std::cout << "stack2 = stack" << std::endl;
            stack2 = stack;
            std::cout << std::boolalpha;
            std::cout << "stack == stack2: " << (stack == stack2) << std::endl;
            std::cout << "stack < stack2: " << (stack < stack2) << std::endl;
            std::cout << "stack2.push(3)" << std::endl;
            stack2.push(3);
            std::cout << "stack2 == stack2: " << (stack == stack2) << std::endl;
            std::cout << "stack2 < stack2: " << (stack < stack2) << std::endl;
            std::cout << "stack size = " << stack.size() << std::endl;
            std::cout << "stack empty = " << stack.empty() << std::endl;
            std::cout << "stack top = " << stack.top() << std::endl;
            std::cout << "stack2 size = " << stack2.size() << std::endl;
            std::cout << "stack2 top = " << stack2.top() << std::endl;
        }
    }
}

int main()
{
    test_vector();
    map_test();
    stack_test();
}