#ifndef PARTNER_LIST_H
#define PARTNER_LIST_H

#include "TDefs.h"
// #include "Heap.h"
#include <vector>
#include <memory>

class PartnerList {
public:
    typedef typename std::pair<RankType, VertexPtr> PartnerType;
    typedef typename std::vector<PartnerType> ContainerType;
    typedef ContainerType::iterator Iterator;
    typedef ContainerType::const_iterator ConstIterator;
    typedef ContainerType::size_type SizeType;

private:
    ContainerType partners_;

public:
    PartnerList();
    virtual ~PartnerList();

    bool empty() const;
    SizeType size() const;
    ConstIterator cbegin() const;
    ConstIterator cend() const;
    Iterator begin();
    Iterator end();

    /// is this vertex in the list
    ConstIterator find(VertexPtr v) const;

    /// add a vertex to the list of matched partners
    void add_partner(const PartnerType& partner);

    /// return details for the worst partner matched to this vertex
    Iterator get_least_preferred();

    /// remove this partner from the list
    void remove(VertexPtr v);

    /// remove the least preferred among the current partners
    void remove_least_preferred();

    RankType get_rank(const ConstIterator& it) const;
    RankType get_rank(const Iterator& it) const;
    VertexPtr get_vertex(const ConstIterator& it) const;
    VertexPtr get_vertex(const Iterator& it) const;

    friend std::ostream& operator<<(std::ostream& out, PartnerList& pl);
    friend std::ostream& operator<<(std::ostream& out, PartnerList* pl);
};

#endif
