/* Inlcude Administration System

	* Desenvolvedor: ProKillerPa
	* Utilizador: City Of Life - RP

*/


#include a_samp
#include zcmd
#include DOF2
#include sscanf2

new ID;

enum Admin1{
	LevelAdmin
}; new Admin[MAX_PLAYERS][Admin1];


forward _OnPlayerConnect(playerid);
public _OnPlayerConnect(playerid){

	Admin[playerid][LevelAdmin] = DOF2_GetInt(AdminPast(playerid), "AdminLevel");
	
	if(Admin[playerid][LevelAdmin] == 1){
	    new _Str[256], Nome[MAX_PLAYER_NAME];
	    
	    GetPlayerName(playerid, Nome, sizeof(Nome));
	    
	    format(_Str, sizeof(_Str), "| CL-Admin | A Conta %s foi vinculada com sucesso para nível de administração de Ajudante!", Nome);
	    SendClientMessage(playerid, -1, _Str);
	
	}
	return 1;
}



CMD:ir(playerid, params[]){

	new Str[128],
	    Str2[128],
		AdminQual[MAX_PLAYER_NAME],
		PlayerQual[MAX_PLAYER_NAME]
	;

	new
	    Float:pX,
        Float:pY,
        Float:pZ
	;
	
	if(sscanf(params, "u", ID)){
	    SendClientMessage(playerid, -1, "| ERRO | /ir [ID]");
	
	} else {
		if(Admin[playerid][LevelAdmin] >= 1){
		    if(!IsPlayerConnected(ID)) 
				return SendClientMessage(playerid, -1, "| ERRO | O(A) Jogador(a) não está conectado(a) no servidor!");
		
		    if(ID == playerid)
		        return SendClientMessage(playerid, -1, "| ERRO | O ID inserido corresponde ao seu, insira um corretamente!");
		
			GetPlayerPos(playerid, pX, pY, pZ); // Pos Player
			
			GetPlayerName(playerid, AdminQual, sizeof(AdminQual));
			GetPlayerName(ID, PlayerQual, sizeof(PlayerQual));
			
			SetPlayerPos(playerid, pX, pY, pZ);
            SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(ID));
            SetPlayerInterior(playerid, GetPlayerInterior(ID));
			
			format(Str, sizeof(Str), "| CL-RP | O(A) Administrador(a) %s veio até você!", AdminQual);
			format(Str2, sizeof(Str2), "| CL-RP | Você foi teleportado até o(a) jogador(a) %d!", PlayerQual);
			
			TogglePlayerControllable(ID, false);

			SendClientMessage(ID, -1, Str);
			SendClientMessage(playerid, -1, Str2);
			
		}
	}
	return 1;
}


AdminPast(playerid){
	new Str[128],
		AdminX[MAX_PLAYER_NAME]
	;
	
	GetPlayerName(playerid, AdminX, sizeof(AdminX));
	
	format(Str, sizeof(Str), "Dados/Cadastros/%s.ini", AdminX);
	return Str;
}