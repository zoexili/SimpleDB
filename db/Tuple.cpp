#include <db/Tuple.h>
#include <cassert>

using namespace db;

//
// Tuple
//

// TODO pa1.1: implement
// initialize your private member variables with the provided arguments
Tuple::Tuple(const TupleDesc &td, RecordId *rid) {
    // assert(td.numFields() > 0);
    tpField.resize(td.numFields());
    this->tpDesc = td;
    this->rId = rid;
}

const TupleDesc &Tuple::getTupleDesc() const {
    // TODO pa1.1: implement
    return tpDesc;
}

const RecordId *Tuple::getRecordId() const {
    // TODO pa1.1: implement
    return rId;
}

void Tuple::setRecordId(const RecordId *id) {
    // TODO pa1.1: implement
    rId = id;
}

const Field &Tuple::getField(int i) const {
    // TODO pa1.1: implement
    if (i >= 0 && i < tpField.size()) {
        return *tpField[i];
    } 
}

void Tuple::setField(int i, const Field *f) {
    // TODO pa1.1: implement
    if (i >= 0 && i < tpField.size()) {
    tpField[i] = const_cast<Field*>(f);
    }
}

Tuple::iterator Tuple::begin() const {
    // TODO pa1.1: implement
    return tpField.begin();
}   

Tuple::iterator Tuple::end() const {
    // TODO pa1.1: implement
    return tpField.end();
}

std::string Tuple::to_string() const {
    // TODO pa1.1: implement
    std::string str;
    for (auto it = tpField.begin(); it != tpField.end(); it++) {
        str += (*it)->to_string();
        if (std::next(it) != tpField.end()) {
            str += ", ";
        }
    }
    return str;
}
