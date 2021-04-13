#ifndef SYM_COMMON
#define SYM_COMMON
#define interface class
namespace SymCommon
{
    template <class T>
    struct LinkNode
    {
        T *data;
        LinkNode *next;
        LinkNode *prev;
    };

    template <class T>
    void AddBeforeRoot(LinkNode<T> &root, LinkNode<T> &src)
    {
        src.next = &root;
        src.prev = root.prev;
        root.prev->next = &src;
        root.prev = &src;
    }

    template <class T>
    void DelSrc(LinkNode<T> &src)
    {
        src.next->prev = src.prev;
        src.prev->next = src.next;
    }
};
#endif