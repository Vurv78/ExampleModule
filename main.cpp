#define GMMODULE
#include "module_base/include/GarrysMod/Lua/Interface.h"
#include <stdio.h>

using namespace GarrysMod::Lua;

int MyExampleFunction( lua_State* state )
{
	if ( LUA->IsType( 1, Type::NUMBER ) )
	{
		char strOut[512];
		float fNumber = LUA->GetNumber( 1 );
		sprintf( strOut, "Thanks for the number - I love %f!!", fNumber );
		LUA->PushString( strOut );
		return 1;
	}

	LUA->PushString( "This string is returned" );
	return 1;
}


GMOD_MODULE_OPEN() {
	LUA->PushSpecial( GarrysMod::Lua::SPECIAL_GLOB );
	LUA->PushString( "TestFunction" );
	LUA->PushCFunction( MyExampleFunction );
	LUA->SetTable( -3 );

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}