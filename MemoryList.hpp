#include <assert.h>


template< typename NODE >
void kernel::CMemoryList< NODE >::Delete( PNODE pEntry )
{
	--m_Size;

	if ( m_pHead == m_pTail )
	{
		m_pHead = m_pTail = NULL;
	}
	else if ( m_pHead == pEntry )
	{
		m_pHead = pEntry->Next;
		m_pHead->Prev = NULL;
	}
	else if ( m_pTail == pEntry )
	{
		m_pTail = pEntry->Prev;
		m_pTail->Next = NULL;
	}
	else
	{
		pEntry->Prev->Next = pEntry->Next;
		pEntry->Next->Prev = pEntry->Prev;
	}

	pEntry->Next = pEntry->Prev = NULL;

	assert( Size() == m_Size );
}

template< typename NODE >
void kernel::CMemoryList<NODE>::Clear()
{
	m_pHead = m_pTail = NULL;
	m_Size = 0;

	assert( Size() == m_Size );
}

template< typename NODE >
inline DWORD kernel::CMemoryList< NODE >::Size()
{
	DWORD Size = 0;

	for ( PNODE pEntry = m_pHead; NULL != pEntry; pEntry = pEntry->Next )
	{
		++Size;
	}

	return Size;
}
