#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "EventDispatcher.h"
#include "StateManager.h"
#include "Context.h"

using ::testing::_;
using ::testing::Invoke;

class MockStateManager : public StateManager
{
public:
  MOCK_METHOD(void, handleEvent, (const std::string &event, std::function<void(Context &)> handler, Context &context), (override));
};

TEST(EventDispatcherTests, DispatchEvent_CallsHandleEventOnStateManager)
{
  MockStateManager mockManager;
  EventDispatcher dispatcher(mockManager);

  Context context;
  bool handlerCalled = false;

  auto handler = [&](Context &ctx)
  {
    handlerCalled = true;
    (void)ctx;
  };

  EXPECT_CALL(mockManager, handleEvent("test_event", _, context))
      .WillOnce(Invoke([&](const std::string &, std::function<void(Context &)> handler, Context &)
                       { handler(context); }));

  dispatcher.dispatchEvent("test_event", handler, context);

  EXPECT_TRUE(handlerCalled);
}
