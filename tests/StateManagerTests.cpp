#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "StateManager.h"
#include "QuestionStateInterfaces.h"
#include "Context.h" // Подключаем реальный Context

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Invoke;

class MockQuestState : public IQuestState
{
public:
  MOCK_METHOD(void, enter, (), (override));
  MOCK_METHOD(void, exit, (), (override));
  MOCK_METHOD(void, handleEvent, (const std::string &event), (override));
};

TEST(StateManagerTests, SetCurrentState_CallsExitAndEnter)
{
  StateManager manager;
  auto state1 = std::make_shared<MockQuestState>();
  auto state2 = std::make_shared<MockQuestState>();

  EXPECT_CALL(*state1, exit()).Times(1);
  EXPECT_CALL(*state2, enter()).Times(1);

  manager.setCurrentState(state1);
  manager.setCurrentState(state2);
}

TEST(StateManagerTests, SetCurrentState_EnterCalledOnFirstSet)
{
  StateManager manager;
  auto state = std::make_shared<MockQuestState>();

  EXPECT_CALL(*state, enter()).Times(1);

  manager.setCurrentState(state);
}

TEST(StateManagerTests, HandleEvent_CallsHandlerIfStateSet)
{
  StateManager manager;
  auto state = std::make_shared<MockQuestState>();
  manager.setCurrentState(state);

  Context context; // Используем реальный Context
  bool handlerCalled = false;

  auto handler = [&](Context &ctx)
  {
    handlerCalled = true;
    (void)ctx; // suppress unused variable warning
  };

  manager.handleEvent("test_event", handler, context);

  EXPECT_TRUE(handlerCalled);
}

TEST(StateManagerTests, EnterCurrentState_CallsEnter)
{
  StateManager manager;
  auto state = std::make_shared<MockQuestState>();

  EXPECT_CALL(*state, enter()).Times(1);

  manager.setCurrentState(state);
  manager.enterCurrentState();
}

TEST(StateManagerTests, ExitCurrentState_CallsExit)
{
  StateManager manager;
  auto state = std::make_shared<MockQuestState>();

  EXPECT_CALL(*state, exit()).Times(1);

  manager.setCurrentState(state);
  manager.exitCurrentState();
}
