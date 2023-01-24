 modded class ActionStartCarCB 
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.START_ENGINE);
	}
};

 modded class ActionStartEngine
{
	private const float ROUGH_SPECIALTY_WEIGHT	= 0.5;
	static const float MINIMUM_BATTERY_ENERGY	= 5.0;	//! DEPRECATED
	
	bool m_BatteryCon	= false; //! DEPRECATED
	bool m_SparkCon		= false; //! DEPRECATED
	bool m_BeltCon		= false; //! DEPRECATED
	bool m_FuelCon		= false; //! DEPRECATED
	bool m_HasBeenStarted = false;
	
	void ActionStartEngine()
	{
		m_CallbackClass 	= ActionStartCarCB;
		m_CommandUID		= DayZPlayerConstants.CMD_ACTIONMOD_STARTENGINE;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_ALL;
		m_SpecialtyWeight	= ROUGH_SPECIALTY_WEIGHT;
		m_LockTargetOnUse	= false;
		m_Text = "#start_the_car";
	}

	override void CreateConditionComponents()  
	{	
		m_ConditionTarget	= new CCTNone;
		m_ConditionItem		= new CCINone;
	}
	



	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{	
		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
		if (vehCommand)
		{
			Transport trans = vehCommand.GetTransport();
			if (trans)
			{
				Car car;
				if (Class.CastTo(car, trans) && !car.EngineIsOn())
				{
					if (car.GetHealthLevel("Engine") >= GameConstants.STATE_RUINED)
					{
						return false;
					}
					
					if (car.CrewMemberIndex(player) == DayZPlayerConstants.VEHICLESEAT_DRIVER)
					{

						if (Class.CastTo(car, trans))
						{

							if(player && !m_HasBeenStarted)
							{

								//ObjectGetDisplayName();
									ItemBase myitem = player.GetItemInHands();
									Object obj,carobj;
									Class.CastTo(obj,myitem);
									Class.CastTo(car,trans);							
									Class.CastTo(carobj,car);
									//ItemBase myitem = player.GetItemInHands();
									Print("xxxxxxxxxxxx you started the car");
									if(myitem)
									{
									//Print(myitem.ToString());
									//int i = carobj.GetID();
									//Print(    carobj.GetID().ToString()  );	
									string s = "";
									string s2 = "";
									string s3 = "";

									GetGame().ObjectGetDisplayName(obj,s);
									Print(  s   );	
									GetGame().ObjectGetDisplayName(carobj,s2);
									Print(  s2   );	

									ItemBase paper_Item;
									//paper_Item = ItemBase.Cast("Paper");

									Param1<string> text = new Param1<string>( "hello kitty" );
									//Param1<string> text = "hello kitty";
									paper_Item.RPCSingleParam(ERPCs.RPC_WRITE_NOTE, text, true,player.GetIdentity());
//player.CreateInInventory("Paper");
									m_HasBeenStarted = true;	
									}
									else
									{
									Print("xxxxxxxyou started the car with nothing in your hands");
									}					
							}

						return true;		                  			
						}

					}
				}
			}
		}

		return false;
	}








	override void OnFinishProgressServer(ActionData action_data)
	{
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if (vehCommand)
		{
			Transport trans = vehCommand.GetTransport();
			if (trans)
			{
				CarScript car;
				if (Class.CastTo(car, trans))
				{
					car.EngineStart();
				}

	
			}
		}
	}
	
	override void OnStartServer(ActionData action_data)
	{
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if (vehCommand)
		{
			Transport trans = vehCommand.GetTransport();
			if (trans)
			{
				CarScript car;
				if (Class.CastTo(car, trans))
				{
					car.OnBeforeEngineStart();
				}
			}
		}
	}
	
	override bool CanBeUsedInVehicle()
	{
		return true;
	}
};
