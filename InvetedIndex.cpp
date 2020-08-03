#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class LinkedList
{
public:
    string data;
    LinkedList *head;
    LinkedList *next;
    LinkedList()
    {
        head = next = NULL;
        data = "";
    }
    void Insert(string word)
    {
        LinkedList *newNode = new LinkedList();
        newNode->data = word;
        newNode->next = NULL;
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            LinkedList *temp=head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    bool search_word(string word)
    {
        LinkedList *temp=head;
        while(temp)
        {
            if(temp->data == word)
            {
                return true;
            }
            else
            {
                temp=temp->next;
            }
        }
        return false;
    }
    void print()
    {
        LinkedList *temp=head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
class InvertedIndex
{
public:
    LinkedList *Doc1;
    LinkedList *Doc2;
    LinkedList *Doc3;
    LinkedList *Doc4;
    LinkedList *Doc5;
    LinkedList *Doc6;
    LinkedList *Doc7;
    LinkedList *Doc8;
    int i;
    InvertedIndex()
    {
        i=1;
        Doc1 = new LinkedList();
        Doc2 = new LinkedList();
        Doc3 = new LinkedList();
        Doc4 = new LinkedList();
        Doc5 = new LinkedList();
        Doc6 = new LinkedList();
        Doc7 = new LinkedList();
        Doc8 = new LinkedList();
    }
    void InsertWord(string filename , LinkedList *obj)
    {
        ifstream Infile(filename.c_str());
        string abc;
        while(!Infile.eof())
        {
            Infile>>abc;
            obj->Insert(abc);
        }
        Infile.close();
    }
    void InsertDoc()
    {
        InsertWord("Doc.1.txt", Doc1);
        InsertWord("Doc.2.txt", Doc2);
        InsertWord("Doc.3.txt", Doc3);
        InsertWord("Doc.4.txt", Doc4);
        InsertWord("Doc.5.txt", Doc5);
        InsertWord("Doc.6.txt", Doc6);
        InsertWord("Doc.7.txt", Doc7);
        InsertWord("Doc.8.txt", Doc8);
        cout<<"Input Completed"<<endl;
    }
    void SearchWord(LinkedList *obj)
    {
        ofstream outfile("output.txt",std::ios_base::app);
        string word;
        LinkedList *temp = obj->head;
        while(temp)
        {
            word = temp->data;
            outfile<<i++<<std::setw(15)<<word;
            if(Doc1->search_word(word))
            {
                outfile<<std::setw(10)<<"\tYes\t\t";
            }
            else
            {
                outfile<<std::setw(10)<<"\tNO\t\t";
            }
            if(Doc2->search_word(word))
            {
                outfile<<std::setw(10)<<"\tYes\t\t";
            }
            else
            {
                outfile<<std::setw(10)<<"\tNO\t\t";
            }
            if(Doc3->search_word(word))
            {
                outfile<<std::setw(10)<<"\tYes\t\t";
            }
            else
            {
                outfile<<std::setw(10)<<"\tNO\t\t";
            }
            if(Doc4->search_word(word))
            {
                outfile<<std::setw(10)<<"\tYes\t\t";
            }
            else
            {
                outfile<<std::setw(10)<<"\tNO\t\t";
            }
            if(Doc5->search_word(word))
            {
                outfile<<std::setw(10)<<"\tYes\t\t";
            }
            else
            {
                outfile<<std::setw(10)<<"\tNO\t\t";
            }
            if(Doc6->search_word(word))
            {
                outfile<<std::setw(10)<<"\tYes\t\t";
            }
            else
            {
                outfile<<std::setw(10)<<"\tNO\t\t";
            }
            if(Doc7->search_word(word))
            {
                outfile<<std::setw(10)<<"\tYes\t\t";
            }
            else
            {
                outfile<<std::setw(10)<<"\tNO\t\t";
            }
            if(Doc8->search_word(word))
            {
                outfile<<std::setw(10)<<"\tYes\t\t";
            }
            else
            {
                outfile<<std::setw(10)<<"\tNO\t\t";
            }
            outfile<<endl;
            temp = temp->next;
        }
        outfile.close();
    }
    void SearchDoc()
    {
        ofstream outfile("output.txt");
        outfile<<" ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        outfile<<"|\tWords\t|\tDocument1\t|\tDocument2\t|\tDocument3\t|\tDocument4\t|\tDocument5\t|\tDocument6\t|\tDocument7\t|\tDocument8 \t|\n";
        outfile<<" ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        SearchWord(Doc1);
        SearchWord(Doc2);
        SearchWord(Doc3);
        SearchWord(Doc4);
        SearchWord(Doc5);
        SearchWord(Doc6);
        SearchWord(Doc7);
        SearchWord(Doc8);
        cout<<"Output File Created"<<endl;
    }
};
int main()
{
    InvertedIndex *Index = new InvertedIndex();
    Index->InsertDoc();
    Index->SearchDoc();
    return 0;
}
