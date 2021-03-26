
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
输入：[1, 2, 3, 3, 2, 1]
输出：[1, 2, 3]
*/
ListNode* removeDuplicateNodes(ListNode* head)
{
	if (nullptr == head)
	{
	    return nullptr;
	}

	unordered_set<int> hashSet = {head->val};

	ListNode* pCurNode = head;
	while (nullptr != pCurNode && nullptr != pCurNode->next)
	{
	    if (hashSet.end() != hashSet.find(pCurNode->next->val))
	    {
		pCurNode->next = pCurNode->next->next;
	    }
	    else
	    {
		hashSet.insert(pCurNode->next->val);
		pCurNode = pCurNode->next;
	    }
	}

	return head;
}


/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次。
返回同样按升序排列的结果链表。
输入：head = [1,1,2]
输出：[1,2]
*/

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
			pCurNode->next = pCurNode->next->next;
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
