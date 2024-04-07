#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED 

typedef char* String;

typedef struct list List;

typedef int value_list_data; 

typedef struct
{
	String key;
	List *values_list;
}key_list_data; 

typedef union
{
	key_list_data keyPair;
	value_list_data value;
}Data;


#endif
