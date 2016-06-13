#pragma once

namespace kernel {
//////////////////////////////////////////////////////////////////////////
template< typename NODE >
class CMemoryList
{
public:
	typedef NODE* PNODE;

public:
	CMemoryList();

public:
	void PushBack( PNODE pEntry );
	void Delete( PNODE pEntry );
	void Replace( PNODE pEntry, PNODE pNewEntry );
	void Clear();

public:
	PNODE Head() { return m_pHead; }
	PNODE Tail() { return m_pTail; }

public:
	bool Empty() const { return NULL == m_pHead; }

	DWORD Size();

public:
	PNODE m_pHead;
	PNODE m_pTail;

	DWORD m_Size;
};
//////////////////////////////////////////////////////////////////////////
} /* namespace kernel */

#include "MemoryList.hpp"