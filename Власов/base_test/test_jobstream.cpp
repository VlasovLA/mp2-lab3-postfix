#include "TJobStream.h"
#include "TJobStream.cpp"
#include <gtest.h>

TEST(TJobStream, can_create_object)
{
	ASSERT_NO_THROW(TJobStream j(10, 50));
}

TEST(TJobStream, throws_when_try_create_object_with_negative_size_queue)
{
	EXPECT_ANY_THROW(TJobStream j(-4, 40));
}

TEST(TJobStream, throws_when_try_create_object_with_negative_intensity)
{
	EXPECT_ANY_THROW(TJobStream j(10, -5));
}

TEST(TJobStream, throws_when_try_create_object_with_too_large_intensity)
{
	EXPECT_ANY_THROW(TJobStream j(10, 120));
}

TEST(TJobStream, can_get_new_task)
{
	TJobStream j(10, 50);
	ASSERT_NO_THROW(j.GetNewTask());
}

TEST(TJobStream, can_generate_new_task)
{
	TJobStream j(10, 50);
	ASSERT_NO_THROW(j.GetNewTask());
}
