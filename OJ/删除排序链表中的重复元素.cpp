/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次。
返回同样按升序排列的结果链表。
输入：head = [1,1,2]
输出：[1,2]
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
	if (nullptr == head)
	{
		return nullptr;
	}

	ListNode* pCurNode = head;
	while (nullptr != pCurNode && nullptr != pCurNode->next)
	{
		if (pCurNode->val == pCurNode->next->val)
		{
			ListNode *pTempNode = pCurNode->next;
			pCurNode->next = pTempNode->next;
			delete pTempNode;
		}
		else
		{
			pCurNode = pCurNode->next;
		}
	}

	return head;
}

/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
返回同样按升序排列的结果链表。
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
*/
