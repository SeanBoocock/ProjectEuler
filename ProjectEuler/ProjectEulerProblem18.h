#pragma once

#include "ProjectEulerProblem.h"

#include <array>
#include <string>
#include <sstream>

//By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

//3
//7 4
//2 4 6
//8 5 9 3
//
//That is, 3 + 7 + 4 + 9 = 23.
//
//Find the maximum total from top to bottom of the triangle below :
//
//75
//95 64
//17 47 82
//18 35 87 10
//20 04 82 47 65
//19 01 23 75 03 34
//88 02 77 73 07 63 67
//99 65 04 28 06 16 70 92
//41 41 26 56 83 40 80 70 33
//41 48 72 33 47 32 37 16 94 29
//53 71 44 65 25 43 91 52 97 51 14
//70 11 33 28 77 73 17 78 39 68 17 57
//91 71 52 38 17 14 91 43 58 50 27 29 48
//63 66 04 68 89 53 67 30 73 16 69 87 40 31
//04 62 98 27 23 09 70 98 73 93 38 53 60 04 23


class ProjectEulerProblem18 : ProjectEulerProblem<18>
{
	struct Node
	{
		uint32_t MaxSumToNode;
		uint8_t Value;
	};

	typedef std::array<Node, 120> TreeArray;

	void InitializeTree(TreeArray& tree)
	{
		const std::string treeStr = R"(75
								95 64
								17 47 82
								18 35 87 10
								20 04 82 47 65
								19 01 23 75 03 34
								88 02 77 73 07 63 67
								99 65 04 28 06 16 70 92
								41 41 26 56 83 40 80 70 33
								41 48 72 33 47 32 37 16 94 29
								53 71 44 65 25 43 91 52 97 51 14
								70 11 33 28 77 73 17 78 39 68 17 57
								91 71 52 38 17 14 91 43 58 50 27 29 48
								63 66 04 68 89 53 67 30 73 16 69 87 40 31
								04 62 98 27 23 09 70 98 73 93 38 53 60 04 23)";


		std::stringstream stream(treeStr);
		TreeArray::size_type index = 0;
		while (!stream.eof())
		{
			uint32_t val;
			stream >> val;
			tree[index++].Value = static_cast<uint8_t>(val);
		}
	}
	
	// Proposed algorithm: BFS exploration, store max path to a node in that node; keep track of max sum to a node at
	// bottom of tree.
	// O(nlogn)
	virtual void ExecuteProblem() final
	{
		TreeArray tree{};
		InitializeTree(tree);

		auto updateSumToNode = [](Node& visiting, const uint32_t sumToNode) { if (visiting.MaxSumToNode < sumToNode) { visiting.MaxSumToNode = sumToNode; }};
		for (TreeArray::size_type row = 0, rowMax = 14, parentIdx = 0; row < rowMax; ++row)
		{
			for (TreeArray::size_type col = 0, colMax = row + 1; col < colMax; ++col, ++parentIdx)
			{
				const auto& parent = tree[parentIdx];
				auto& leftChild = tree[parentIdx + colMax];
				auto& rightChild = tree[parentIdx + colMax + 1];

				const auto maxValue = parent.MaxSumToNode + parent.Value;
				updateSumToNode(leftChild, maxValue);
				updateSumToNode(rightChild, maxValue);
			}
		}

		// Iterate over last row and calculate max(MaxSumToNode + Value) over the nodes
		uint64_t sum = 0;
		for (auto it = tree.rbegin(), end = tree.rbegin() + 15; it != end; ++it)
		{
			const uint64_t nodeSum = it->MaxSumToNode + it->Value;
			if (nodeSum > sum)
			{
				sum = nodeSum;
			}
		}
	
		std::cout << "The maximum total from top to bottom of the triangle is " << sum;
	}
} g_problem18;
