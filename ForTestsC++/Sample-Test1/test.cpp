#include "pch.h"
#include "../ForTestsC++/NewClass.h"

TEST(TestCaseName, TestName) {
	NewClass nc;
  EXPECT_EQ(nc.sum(1,2), 3);//������������� ������������
  EXPECT_TRUE(true);//�����������
}