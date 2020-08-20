#include "CTRPluginFramework/System/Task.hpp"

namespace CTRPluginFramework
{
    Task::Task(TaskFunc func, void *arg = nullptr, s32 affinity)
    {
    	u32 *v8 = new u32[0x20];
    	u32 *v9 = new u32[0x20];
    	u32 *ptr = memset(v8, 0, 0x20u);
    	u32 v11;
    	context->refcount = v8;
    	__mcr(15, 0, context->refcount, 7, 10, 5);
    	do
    		v11 = __ldrex(v8);
    	while ( __strex(v11 + 1, v8) );
    	__mcr(15, 0, context->refcount, 7, 10, 5);
    	context->affinity = affinity;
    	context->func = func;
    	context->arg = arg;
    	LightEvent_Init(&context->event);
        delete v8, v9, ptr;
    }

    Task::Task(const Task &task)
    {
    	u32 *v2 = new u32[0x20];
    	u32 v3 = 0;
    	__mcr(15, 0, context->refcount, 7, 10, 5);
    	do
    		v3 = __ldrex(v2);
    	while ( __strex(v3 + 1, v2) );
    	__mcr(15, 0, context->refcount, 7, 10, 5);
        context->affinity = task.context->affinity;
        context->func = task.context->func;
        context->arg = task.context->arg;
        LightEvent_Init(&context->event);
        delete v2;
    }

    Task::Task(Task &&task)
    {
        context = task.context;
    }

    Task::~Task(void)
    {
    	u32 v4
    	if (context->refcount)
    	{
    		__mcr(15, 0, (u32)context, 7, 10, 5);
    		do
    		{
    			v4 = __ldrex(*(u32 **)context) - 1;
    		}
    		while ( __strex(v4, *(u32 **)context) );
    		__mcr(15, 0, (u32)refcount, 7, 10, 5);
    		if (!v4)
    			delete context;
    	}
    }

    int Task::Start(void) const
    {
    	if (!context->refcount)
    		return -1;
    	LightEvent_Clear(&context->event);
    	return Scheduler::Schedule(context->refcount);
    }

    s32 Task::Wait(void) const
    {
    	if ( !context->refcount )
    		return -1;
    	if ( !context->flags & 0xFFFFFFFB) )
    		return context->result;
    	LightEvent_Wait(&context->event);
    	return context->result;
    }

    u32 Task::Status(void) const
    {
    	if (context->refcount)
            return context->flags;
    	return -1;
    }
}
