struct DLL
{
    int val;
    DLL *next;
    DLL *prev;
    DLL() : val(0), next(nullptr), prev(nullptr) {}
    DLL(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class FrontMiddleBackQueue
{
public:
    int curSize = 0;
    DLL *LL = nullptr;
    DLL *front = nullptr;
    DLL *middle = nullptr;
    DLL *rear = nullptr;

    FrontMiddleBackQueue() {}

    void pushFront(int value)
    {
        if (curSize == 0)
        {
            LL = new DLL(value);
            front = LL;
            rear = LL;
            middle = LL;
        }
        else
        {
            DLL *D = new DLL(value);
            D->next = front;
            front->prev = D;
            front = D;
            if (curSize & 1)
            {
                middle = middle->prev;
            }
        }
        curSize++;
    }

    void pushMiddle(int value)
    {
        if (curSize == 0)
        {
            LL = new DLL(value);
            front = LL;
            rear = LL;
            middle = LL;
        }
        else if (curSize == 1)
        {

            DLL *D = new DLL(value);
            D->next = middle;
            middle->prev = D;
            middle = D;
            front = D;
        }
        else
        {
            if (curSize & 1)
            {
                DLL *D = new DLL(value);
                D->next = middle;
                D->prev = middle->prev;
                middle->prev->next = D;
                middle->prev = D;
                middle = D;
            }
            else
            {
                DLL *D = new DLL(value);
                D->next = middle->next;
                D->prev = middle;
                middle->next = D;
                D->next->prev = D;
                middle = D;
            }
        }
        curSize++;
    }

    void pushBack(int value)
    {
        if (curSize == 0)
        {
            LL = new DLL(value);
            front = LL;
            rear = LL;
            middle = LL;
        }
        else
        {
            rear->next = new DLL(value);
            rear->next->prev = rear;
            rear = rear->next;
            if (!(curSize & 1))
            {
                middle = middle->next;
            }
        }
        curSize++;
    }

    int popFront()
    {
        if (!curSize)
        {
            return -1;
        }
        int v = front->val;
        if (curSize == 1)
        {
            LL = rear = front = middle = nullptr;
        }
        else
        {
            if (!(curSize & 1))
            {
                middle = middle->next;
            }
            front = front->next;
            front->prev = nullptr;
        }
        curSize--;
        return v;
    }

    int popMiddle()
    {
        if (!curSize)
        {
            return -1;
        }
        int v = middle->val;

        if (curSize == 1)
        {
            LL = rear = front = middle = nullptr;
        }
        else if (curSize == 2)
        {
            LL = rear = front = middle = front->next;
        }
        else
        {
            middle->next->prev = middle->prev;
            middle->prev->next = middle->next;
            if (curSize & 1)
            {
                middle = middle->prev;
            }
            else
            {
                middle = middle->next;
            }
        }
        curSize--;
        return v;
    }

    int popBack()
    {
        if (!curSize)
        {
            return -1;
        }
        int v = rear->val;
        if (curSize == 1)
        {
            LL = rear = front = middle = nullptr;
        }
        else
        {
            if (curSize & 1)
            {
                middle = middle->prev;
            }
            rear = rear->prev;
            rear->next = nullptr;
        }
        curSize--;
        return v;
    }
};