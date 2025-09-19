#include "list.h"

void initialize_list(SortedList *list)
{
    list->head = NULL; // Lista jest pusta.
}

void add(SortedList *list, void *data, CMP cmp)
{
    Node *new_node = malloc(sizeof(Node)); // Alokacja nowego węzła, w który "opakujemy" data.
    if (new_node == NULL)
        return;
    new_node->data = data; // Wskaźnik do przekazanego data przypisujemy nowemu węzłowi.

    // Zostało przeszukanie listy w celu znalezienia miejsca, gdzie (zgodnie z sortowaniem) mamy wstawić nowy węzeł.
    Node *previous = NULL;      // Zmienna pomocnicza: poprzedni węzeł (wskaźnik do niego).
    Node *current = list->head; // Zmienna pomocnicza: aktualny węzeł (zaczynamy od head, bo wskazuje na pierwszy węzeł).
    // Pętla skończy się, gdy przeszuka całą listę (pierwszy warunek) lub gdy znajdzie miejsce, gdzie trzeba wstawić nowy węzeł.
    while (current != NULL && cmp(current->data, data) < 0)
    {
        previous = current;      // Aktualny stanie się poprzednim w następnym obiegu.
        current = current->next; // Przesuwamy wskaźnik do aktualnego, żeby w kolejnym obiegu zająć się następnym węzłem.
    }
    new_node->next = current;  // Następny po nowym węźle ma być current. Jeśli nowy ma być ostatnim na liście lub lista była pusta, to przypisze się NULL.
    if (previous == NULL)      // Przypadek, gdy wszystkie dane na liście są większe od data: new_node wstawiamy przed head, czyli przestawiamy tez head.
        list->head = new_node; // Wykona się też, gdy lista jest pusta: wówczas też new_node ma być nowym head.
    else
        previous->next = new_node; // Nowy węzeł wstawiamy między previous a current, więc następny po previous ma być new_node.
}

void *get_data(const SortedList *list, CMP cmp, const void *data)
{
    Node *current = list->head; // Przeszukiwanie zaczynamy od pierwszego węzła.
    while (current != NULL)     // Póki nie trafimy na koniec listy:
    {
        if (cmp(current->data, data) == 0) // Jeśli aktualny węzeł (current) przechowuje dane o zawartości równej zawartości danych wskazywanych przez data, to:
            return current->data;          // zwracamy wskaźnik do danych tego węzła (np. w celu aktualizacji zawartości).
        current = current->next;           // Przechodzimy do kolejnego węzła.
    }
    return NULL; // Jeśli nie znaleziono węzła z takimi samymi danymi.
}

void remove_data(SortedList *list, CMP cmp, void *data)
{
    Node *previous = NULL;      // Zmienna pomocnicza: poprzedni węzeł (wskaźnik do niego).
    Node *current = list->head; // Zmienna pomocnicza: aktualny węzeł (zaczynamy od head, bo wskazuje na pierwszy węzeł).
    // Pętla skończy się, gdy przeszuka całą listę (pierwszy warunek) lub gdy znajdzie węzeł z szukanymi danymi.
    while (current != NULL && cmp(current->data, data) != 0)
    {
        previous = current;
        current = current->next;
    }
    if (current != NULL) // Bo jeśli byłby == NULL, to znaczy, że na liście nie ma szukanych danych: nie ma nic do usunięcia.
    {
        if (previous == NULL)           // Przypadek, gdy poprzedniego nie ma, czyli usuwamy head (pierwszy węzeł).
            list->head = current->next; // Następca current zostaje nowym początkiem.
        else
            previous->next = current->next; // Usuwamy current, więc wskaźnik do jego następcy musi być przepisany do next jego poprzednika.
        free(current);                      // Dopiero teraz można zwolnić pamięć po current.
    }
}

void remove_all(SortedList *list)
{
    Node *current = list->head; // Zmienna pomocnicza: aktualny węzeł.
    while (current != NULL)
    {
        Node *to_remove = current; // Zapamiętujemy wskaźnik, żeby zwolnić po nim pamięć, ale najpierw:
        current = current->next;   // przesuwamy wskaźnik na następny węzeł.
        free(to_remove);           // Dopiero teraz można zwolnić.
    }
    list->head = NULL; // Lista stała się pusta: nie ma początkowego węzła.
}

void print_list(const SortedList *list, PRINT print)
{
    printf("LISTA:\n");
    Node *current = list->head;
    while (current != NULL)
    {
        print(current->data); // Wypisanie danych przechowywanych przez aktualny (jeden) węzeł.
        current = current->next;
    }
}

void merge_lists(SortedList *list1, SortedList *list2, SortedList *target, CMP cmp)
{
    Node *node1=list1->head;
    Node *node2=list2->head;

    if(node1==NULL)
    {
        if(node2==NULL)
        {
            return;
        }
        else
        {
            while(node2!=NULL)
                {
                    add(target,node2->data,cmp);
                    node2=node2->next;
                }
            return;
        }
    }
    else if (node2==NULL)
    {
        while(node1!=NULL)
            {
                add(target,node1->data,cmp);
                node1=node1->next;
            }
        return;
    }
    

    do
    {
        if(cmp(node1->data,node2->data))
        {
            add(target,node1->data,cmp);
            if(node1->next!=NULL)
            {
                node1=node1->next;
            }
            else
            {
                node1=node1->next;
                while(node2!=NULL)
                {
                    add(target,node2->data,cmp);
                    node2=node2->next;
                }
            }
        }
        else
        {
            add(target,node2->data,cmp);
            if(node2->next!=NULL)
            {
                node2=node2->next;
            }
            else
            {
                node2=node2->next;
                while(node1!=NULL)
                {
                    add(target,node1->data,cmp);
                    node1=node1->next;
                }
            }
        }

    }while (node1!=NULL&&node2!=NULL);
    
}
