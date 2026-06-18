#ifndef STRING_H
#define STRING_H

class String{
	
	char* data;
	int ssize;
	
	public:
		String();
		String(char* str);
		String(const String&);
		String(int x);
		
		char* getdata();
		char getChar(int i);
		
		String append_string(const String &str);
		String append_string(const char &str);
		String append_string(char *&str);
//		String append_string(string& str);
		
		String remove_string(const String &substr);
//		String remove_string(const string &substr);
		String remove_string(const char*&substr);
		String remove_string(const char &chr);
		
		String& assign_string(const String&);
		String& assign_string(char*);
//		String& assign_string(const string&);
		
		bool isEmpty();
		
		bool isEqual(const String&)const;
//		bool isEqual(const string&)const;
		bool isEqual(char *)const;
		
		int index_at(char)const;
		int index_at(const String&)const;
//		int index_at(const string&)const;
		int index_at(char *)const;
		
		int length();
		
		~String();
	
};

#endif
