#include "../headers/List.h"

void sortString(List *keyList)
{

}
void sortInt(List *valueList)
{
    ListEntry e, i;
   int p = 0, w;
   while (!ListEmpty(valueList) && p < ListSize(valueList))
   {
       RetrieveList(valueList, p, &e);
       RetrieveList(valueList, p + 1, &i);

       if (e.value > i.value)
       {
           DeleteList(valueList, p, &e);
           w = 0;
           while (w < ListSize(valueList))
           {
               RetrieveList(valueList, w, &i);

               if (e.value<=i.value)
               {
                   InsertList(valueList, w, e);
                   break;
               }
               w++;
           }
           if (w == ListSize(valueList)) {
               InsertList(valueList, w, e);
           }
       }
       else
       {
           p++;
       }
   }
}

