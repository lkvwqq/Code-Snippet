/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
输入：matrix = [[1]], target = 2
输出：false
*/

// original method
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
  
	if (0 == matrix.size())
	{
		return false;
	}

	vector<int> firstElements;
	for (auto &item : matrix)
	{
		firstElements.push_back(item.at(0));
	}

	auto endIter = lower_bound(firstElements.begin(), firstElements.end(), target);
	if (firstElements.end() != endIter && target == *endIter)
	{
		return true;
	}

	for (int i = endIter - firstElements.begin() - 1; i >= 0; --i)
	{
		if (matrix[i].at(0) > target)
		{
			continue;
		}

		if (target == matrix[i].at(0)
			|| binary_search(matrix[i].begin(), matrix[i].end(), target))
		{
			return true;
		}
	}

	return false;
}

// optimize method
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if (0 == matrix.size())
    {
        return false;
    }

    auto compareFunc = [](const int a, const vector<int> &b) { return a < b[0];};
    auto iter = upper_bound(matrix.begin(), matrix.end(), target, compareFunc);

    if (matrix.begin() == iter)
    {
        return false;
    }

    --iter;
    return binary_search(iter->begin(), iter->end(), target);
}

// method 2 假设二维数组中的一维数组的元素个数相同
bool searchMatrix_2(vector<vector<int>>& matrix, int target)
{
  if (0 == matrix.size())
  {
      return false;
  }
  
	int m = matrix.size(), n = matrix[0].size();
	int low = 0, high = m * n - 1;
	while (low <= high)
  {
		int mid = (high - low) / 2 + low;
		int x = matrix[mid / n][mid % n];
		if (x < target)
    {
			low = mid + 1;
		}
		else if (x > target)
    {
			high = mid - 1;
		}
		else
    {
			return true;
		}
	}
  
	return false;
}
