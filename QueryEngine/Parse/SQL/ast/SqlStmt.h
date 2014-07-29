#ifndef SQL_SQLSTMT_H
#define SQL_SQLSTMT_H

#include <cassert>
#include "Statement.h"

class SqlStmt : public Statement {

public:

	DmlStmt *n1 = NULL;
	DdlStmt *n2 = NULL;
	
	
	explicit SqlStmt(DmlStmt *n1) {
		assert(n1);
		this->n1 = n1;
	}

	explicit SqlStmt(DdlStmt *n2) {
		assert(n2);
		this->n2 = n2;
	}
	
	virtual void accept(Visitor &v) const {
		v.visit(this);
	}
};

#endif // SQL_SQLSTMT_H
