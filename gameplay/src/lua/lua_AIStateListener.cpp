#include "Base.h"
#include "ScriptController.h"
#include "lua_AIStateListener.h"
#include "AIState.h"
#include "AIStateMachine.h"
#include "Base.h"
#include "Game.h"
#include "Ref.h"

namespace gameplay
{

void luaRegister_AIStateListener()
{
    const luaL_Reg lua_members[] = 
    {
        {"stateEnter", lua_AIStateListener_stateEnter},
        {"stateExit", lua_AIStateListener_stateExit},
        {"stateUpdate", lua_AIStateListener_stateUpdate},
        {NULL, NULL}
    };
    const luaL_Reg* lua_statics = NULL;
    std::vector<std::string> scopePath;
    scopePath.push_back("AIState");

    ScriptUtil::registerClass("AIStateListener", lua_members, lua_AIStateListener__init, lua_AIStateListener__gc, lua_statics, scopePath);
}

static AIState::Listener* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "AIStateListener");
    luaL_argcheck(state, userdata != NULL, 1, "'AIStateListener' expected.");
    return (AIState::Listener*)((ScriptUtil::LuaObject*)userdata)->instance;
}

int lua_AIStateListener__gc(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                void* userdata = luaL_checkudata(state, 1, "AIStateListener");
                luaL_argcheck(state, userdata != NULL, 1, "'AIStateListener' expected.");
                ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)userdata;
                if (object->owns)
                {
                    AIState::Listener* instance = (AIState::Listener*)object->instance;
                    SAFE_DELETE(instance);
                }
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_AIStateListener__gc - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_AIStateListener__init(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 0:
        {
            void* returnPtr = (void*)new AIState::Listener();
            if (returnPtr)
            {
                ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                object->instance = returnPtr;
                object->owns = true;
                luaL_getmetatable(state, "AIStateListener");
                lua_setmetatable(state, -2);
            }
            else
            {
                lua_pushnil(state);
            }

            return 1;
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 0).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_AIStateListener_stateEnter(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                AIAgent* param1 = ScriptUtil::getObjectPointer<AIAgent>(2, "AIAgent", false);

                // Get parameter 2 off the stack.
                AIState* param2 = ScriptUtil::getObjectPointer<AIState>(3, "AIState", false);

                AIState::Listener* instance = getInstance(state);
                instance->stateEnter(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_AIStateListener_stateEnter - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_AIStateListener_stateExit(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                AIAgent* param1 = ScriptUtil::getObjectPointer<AIAgent>(2, "AIAgent", false);

                // Get parameter 2 off the stack.
                AIState* param2 = ScriptUtil::getObjectPointer<AIState>(3, "AIState", false);

                AIState::Listener* instance = getInstance(state);
                instance->stateExit(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_AIStateListener_stateExit - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_AIStateListener_stateUpdate(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 4:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL) &&
                lua_type(state, 4) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                AIAgent* param1 = ScriptUtil::getObjectPointer<AIAgent>(2, "AIAgent", false);

                // Get parameter 2 off the stack.
                AIState* param2 = ScriptUtil::getObjectPointer<AIState>(3, "AIState", false);

                // Get parameter 3 off the stack.
                float param3 = (float)luaL_checknumber(state, 4);

                AIState::Listener* instance = getInstance(state);
                instance->stateUpdate(param1, param2, param3);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_AIStateListener_stateUpdate - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 4).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

}
