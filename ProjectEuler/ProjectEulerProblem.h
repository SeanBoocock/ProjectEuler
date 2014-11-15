#pragma once

#include <array>
#include <functional>
#include <iostream>

class ProjectEulerProblemBase
{
public:
	static void RunProblem(unsigned int problemNumber)
	{
		if (problemNumber < MaxProblemCount)
		{
			if (Problems[problemNumber])
			{
				std::cout << "==============================================" << std::endl;
				std::cout << "Project Euler Problem " << problemNumber << ":" << std::endl;
				Problems[problemNumber]();
				std::cout << std::endl;
			}
		}
	}

protected:
	static const unsigned int MaxProblemCount = 500;
	typedef std::array<std::function<void()>, MaxProblemCount> ProblemArray;
	static ProblemArray Problems;
};

ProjectEulerProblemBase::ProblemArray ProjectEulerProblemBase::Problems;

template<unsigned int ProblemNumber>
class ProjectEulerProblem : ProjectEulerProblemBase
{
	static_assert(ProblemNumber < MaxProblemCount, "Problem number exceeds max problem count");

protected:
	ProjectEulerProblem()
	{
		Problems[ProblemNumber] = [this] () { ExecuteProblem(); };
	}
	
	virtual void ExecuteProblem() = 0;
};
