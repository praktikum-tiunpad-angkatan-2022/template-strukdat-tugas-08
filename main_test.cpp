#pragma once

namespace strukdat
{

  namespace priority_queue
  {

    /**
     * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
     */
    template <typename T>
    struct Element
    {
      T data;
      int priority;
      Element *next;
    };

    template <typename T>
    using ElementPtr = Element<T> *;

    /**
     * @brief implemetasi struct untuk queue.
     */
    template <typename T>
    struct Queue
    {
      ElementPtr<T> head;
      ElementPtr<T> tail;
    };

    /**
     * @brief membuat queue baru
     *
     * @return  queue kosong
     */
    template <typename T>
    Queue<T> new_queue()
    {
      Queue<T> Q;
      Q.head = nullptr;
      Q.tail = nullptr;
      return Q;
    }

    /**
     * @brief memasukan data sesuai priority elemen.
     *
     * @param q         queue yang dipakai.
     * @param value     isi dari elemen.
     * @param priority  prioritas elemen yang menentukan urutan.
     */
    template <typename T>
    void enqueue(Queue<T> &q, const T &value, int priority)
    {
      ElementPtr<T> pNew = new Element<T>;
      pNew->data = value;
      pNew->priority = priority;
      pNew->next = nullptr;
      if (q.head == nullptr && q.tail == nullptr)
      {
        q.head = pNew;
        q.tail = pNew;
      }
      else
      {
        ElementPtr<T> pHelp = q.head;
        ElementPtr<T> prev = nullptr;
        while (pNew->priority <= pHelp->priority)
        {
          if (pHelp->next == nullptr)
            break;
          prev = pHelp;
          pHelp = pHelp->next;
        }
        if (pHelp == q.head && pNew->priority > pHelp->priority)
        {
          pNew->next = pHelp;
          q.head = pNew;
        }
        else if (pHelp == q.tail && pNew->priority < pHelp->priority)
        {
          pHelp->next = pNew;
          q.tail = pNew;
        }
        else
        {
          pNew->next = pHelp;
          prev->next = pNew;
        }
      }
    }

    /**
     * @brief mengembalikan isi dari elemen head.
     *
     * @param q   queue yang dipakai.
     * @return    isi dari elemen head.
     */
    template <typename T>
    T top(const Queue<T> &q)
    {
      return q.head->data;
    }

    /**
     * @brief menghapus elemen head queue (First in first out).
     *
     * @param q   queue yang dipakai.
     */
    template <typename T>
    void dequeue(Queue<T> &q)
    {
      ElementPtr<T> curr;
      if (q.head == nullptr && q.tail == nullptr)
      {
        curr = nullptr;
      }
      else if (q.head->next == nullptr)
      {
        curr = q.head;
        q.head = nullptr;
        q.tail = nullptr;
      }
      else
      {
        curr = q.head;
        q.head = q.head->next;
        curr->next = nullptr;
      }
      delete curr;
    }

  } // namespace priority_queue

} // namespace strukdat