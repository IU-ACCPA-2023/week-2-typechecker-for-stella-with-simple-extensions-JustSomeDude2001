//
// Created by justsomedude on 26.03.23.
//

#include "StoredType.h"

namespace Stella {
    const StoredType ST_PLACEHOLDER = StoredType(VisitableTag::tagTypePlaceholder);

    const StoredType ST_NAT = StoredType(VisitableTag::tagTypeNat);
    const StoredType ST_BOOL = StoredType(VisitableTag::tagTypeBool);
    const StoredType ST_IDENT = StoredType(VisitableTag::tagTypeIdent);
    const StoredType ST_FUN = StoredType(VisitableTag::tagTypeFunction);
    const StoredType ST_UNIT = StoredType(VisitableTag::tagTypeUnit);
    const StoredType ST_TUPLE = StoredType(VisitableTag::tagTypeTuple);
    const StoredType ST_SUMTYPE = StoredType(VisitableTag::tagTypeSumType, -1, {}, {}, {ST_PLACEHOLDER, ST_PLACEHOLDER});
}