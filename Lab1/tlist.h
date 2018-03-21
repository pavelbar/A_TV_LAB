#ifndef TLIST_H
#define TLIST_H


//--
#ifndef __TLIST_H__
#define __TLIST_H__


template<class ValType>
class TList
{
private:
    struct TNode
    {
        ValType elem;
        TNode *pNext;
        TNode *pPrev;
        int pos;
    };
    TNode *pFirst;
    mutable TNode *pCurr;//текущий элемент
    int count;
    //методы используемые для работы с текущим элементом,
    //а так же для удобной работы перемещения по списку
    void RePos(bool key);//перемещение
    void FullRePos();//перемещение от 0 до последнего(count-1)
    void SetPos(int position)  const;//установить позицию
public:
    TList();
    TList(const TList &list);
    ~TList();
    void InSertFirst(const ValType &val);
    void InSertLast(const ValType &val);
    void InSertInPos(const int pos, const ValType &val);
    void DeleteFirst();
    void DeleteLast();
    void Delete(const int pos);
    void DeleteAll();
    ValType GetElem(const int pos) const;
    int GetSize() const {return count;}
    bool operator==(const TList &list) const;
    bool operator!=(const TList &list) const;
    TList& operator=(const TList &list);
    void Next() const;//вперед по pNext
    void Back() const;//назад по pPrev;
    void SetElem(const int pos, const ValType &val);
};
#endif

template<class ValType>
 void TList<ValType>::RePos(bool key)
{
     int ind = pCurr->pos;
     while (pCurr->pos != count)
     {
         if (key) pCurr->pos++;
         else pCurr->pos--;
         Next();//перемещаемся далее
     }
     SetPos(ind);
}

 template<class ValType>
 void TList<ValType>::FullRePos()
 {
     int i = 0;
     pCurr = pFirst;
     while (i != count)
     {
         pCurr->pos = i++;
         Next();//перемещаемся далее
     }
 }

 template<class ValType>
 void TList<ValType>::SetPos(int position) const
 {
     if ((position < 0) || position > count) throw(" Invalid position");
         if (position == 0)
         {
             pCurr = pFirst;
         }
         else
         {
             while (pCurr->pos < position)
                 Next();
             while (pCurr->pos > position)
                 Back();
         }
 }

template<class ValType>
 TList<ValType>::TList()
{
     pFirst =pCurr= nullptr;
    count = 0;
}

 template<class ValType>
 TList<ValType>::TList(const TList & list)
 {
     pFirst = pCurr = nullptr;
     count = 0;
     TNode *tmp = list.pFirst;
     while (tmp != nullptr)
     {
         InSertLast(tmp->elem);
         tmp = tmp->pNext;
     }
 }


 template<class ValType>
 TList<ValType>::~TList()
 {
     if (pFirst == nullptr)
     {
         delete pFirst;
         delete pCurr;
     }
     else if (count == 1)
     {
         delete pFirst;
     }
     else
     {
         SetPos(1);
         delete pFirst;
         TNode *p;
         while (pCurr->pos != count - 1)
         {
             p = pCurr;
             Next();
             delete p;
         }
         delete pCurr;
     }
 }


template<class ValType>
void TList<ValType>::InSertFirst(const ValType &val)
{
    if (pFirst == nullptr)
    {
        pFirst = new TNode;
        pFirst->pos = 0;
        pFirst->elem = val;
        pFirst->pNext = pFirst->pPrev = nullptr;
        count++;
    }
    else
    {
        TNode *p = new TNode;
        p->elem = val;
        p->pNext = pFirst;
        p->pPrev = nullptr;
        pFirst=pCurr = p;
        TNode *next = pFirst->pNext;
        next->pPrev = pFirst;
        count++;
        FullRePos();
    }
}
template <class ValType>
void TList<ValType>::InSertInPos(const int pos,const ValType &val)
{
    if ((pos < 0) || (pos > count)) throw("Invalid position");
    if (pos == 0) InSertFirst(val);
    else if (pos == count) InSertLast(val);
    else
    {
        SetPos(pos);//устанавливаем позицию в pCurr;
        TNode *p = new TNode;
        TNode *prev = pCurr->pPrev;
        p->pos = pos;
        p->elem = val;
        pCurr->pPrev = p;
        prev->pNext = p;
        p->pNext = pCurr;
        p->pPrev = prev;
        RePos(1);//идем по позиции далее, т.к вставка
        count++;
    }
}
template<class ValType>
void TList<ValType>::InSertLast(const ValType  &val)
{
    if (pFirst == nullptr)
    {
        InSertFirst(val);
    }
    else
    {
        SetPos(count - 1);//устанавливаем на последний перед вставкой в конец
        TNode *p = new TNode;
        p->elem = val;
        p->pos = count;
        p->pNext = nullptr;
        count++;
        pCurr->pNext = p;//предпоследний теперь указывает на p;
        p->pPrev = pCurr;//
    }
}


template<class ValType>
 void TList<ValType>::DeleteFirst()
{
     if (pFirst == nullptr) return;
     TNode *p = pFirst->pNext;
     delete pFirst;
     p->pPrev = nullptr;
     pCurr = pFirst = p;
     count--;
     FullRePos();
}

 template<class ValType>
 inline void TList<ValType>::DeleteLast()
 {
     if (pFirst == nullptr) return;
     SetPos(count - 1);
     TNode *p = pCurr->pPrev;
     p->pNext = nullptr;
     delete pCurr;
     pCurr = p;
     count--;
 }

 template<class ValType>
 void TList<ValType>::Delete(const int pos)
 {
     if ((pos < 0) || (pos > count)) throw("Invalid position");
     if (pFirst == nullptr) return;
     if (pos == 0) DeleteFirst();
     else if (pos == count - 1) DeleteLast();
     else
     {
         SetPos(pos);
         TNode *prev = pCurr->pPrev;
         TNode *next = pCurr->pNext;
         delete pCurr;
         prev->pNext = next;
         next->pPrev = prev;
         count--;
         FullRePos();
     }
 }

 template<class ValType>
  void TList<ValType>::DeleteAll()
 {
      ::TList<ValType>::~TList();
      pFirst = pCurr = nullptr;
      count = 0;
 }

template<class ValType>
 ValType TList<ValType>::GetElem(const int pos) const
 {
     if (pos<0 || pos>count) throw("there is no such position");
     SetPos(pos);
     return pCurr->elem;
 }

 template<class ValType>
 bool TList<ValType>::operator==(const TList<ValType> &list) const
 {
     if (count != list.count)
         return false;
     TNode *tmp_one, *tmp_two;
     tmp_one = pFirst;
     tmp_two = list.pFirst;
     while (tmp_one != nullptr)
     {
         if (tmp_one->elem != tmp_two->elem)
             return false;
         tmp_one = tmp_one->pNext;
         tmp_two = tmp_two->pNext;
     }
     return true;
 }

 template<class ValType>
 bool TList<ValType>::operator!=(const TList & list) const
 {
     if (*this == list) return false;
     else return true;
 }

 template<class ValType>
 TList<ValType>& TList<ValType>::operator=(const TList<ValType> &list)
 {
     if (*this == list) return *this;
     DeleteAll();
     TNode *tmp = list.pFirst;
     while (tmp!=nullptr)
     {
         InSertLast(tmp->elem);
         tmp = tmp->pNext;
     }
     return *this;
 }

 template<class ValType>
void TList<ValType>::Next() const
 {
    if (pCurr->pNext == nullptr) return;
    pCurr = pCurr->pNext;
 }

template<class ValType>
void TList<ValType>::Back() const
{
    if (pCurr->pPrev == nullptr) return;
    pCurr = pCurr->pPrev;
}

template<class ValType>
 void TList<ValType>::SetElem(const int pos, const ValType &val)
{
    if ((pos < 0) || (pos > count)) throw("Invalid position");
    SetPos(pos);
    pCurr->elem = val;
}

//--

#endif // TLIST_H
