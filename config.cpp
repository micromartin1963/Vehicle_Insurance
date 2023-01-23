
class CfgPatches
{
	class Vehicle_Insurance
	{
		units[] = {"FOG_INS__SILVER","FOG_INS__BRONZE","FOG_INS__GOLD"};
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class Test_Crafting
	{	
		type = "mod";
		
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"Vehicle_Insurance/scripts/4_world"};
			};
		}
	};
};

class CfgVehicles
{


	class Inventory_Base;

	class FOG_INS_Base: Inventory_Base
	{
		scope = 2;
		displayName = "Insurance Book";
		descriptionShort = "Use this to create an insurance certificate for your vehicle";
		model = "\Vehicle_Insurance\data\flagbook2.p3d";
		rotationFlags = 8;
		weight = 10;
		itemSize[] = {2,2};


	};
	class FOG_INS__SILVER: FOG_INS_Base
	{
		scope = 2;
		displayName = "Silver Car insurance";

	};
	class FOG_INS__BRONZE: FOG_INS_Base
	{
		scope = 2;
		displayName = "Bronze Car insurance";

	};
	class FOG_INS__GOLD: FOG_INS_Base
	{
		scope = 2;
		displayName = "Gold Car insurance";

	};

};
