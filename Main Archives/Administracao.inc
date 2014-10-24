/* Inlcude Administration System

	* Desenvolvedor: ProKillerPa
	* Utilizador: City Of Life - RP

*/


#include a_samp
#include zcmd
#include DOF2
#include sscanf2

#define SENHAADMIN 6

new ID;

enum Admin1{
	LevelAdminX
}; new Admin[MAX_PLAYERS][Admin1];

AdminPast(playerid){
	new Str[128],
		AdminX[MAX_PLAYER_NAME]
	;

	GetPlayerName(playerid, AdminX, sizeof(AdminX));

	format(Str, sizeof(Str), "Dados/Cadastros/%s.ini", AdminX);
	return Str;
}

forward NivelAdmin(playerid);
public NivelAdmin(playerid){
	Admin[playerid][LevelAdminX] = DOF2_GetInt(AdminPast(playerid), "AdminLevel");

	new _Str[256], Nome[MAX_PLAYER_NAME];

	GetPlayerName(playerid, Nome, sizeof(Nome));

    if(Admin[playerid][LevelAdminX] >= 1){

		if(Admin[playerid][LevelAdminX] == 1){

		    format(_Str, sizeof(_Str), "| CL-Admin | A Conta %s foi vinculada com sucesso para conta Administrativa nível Ajudante", Nome);
		    SendClientMessage(playerid, -1, _Str);
		}
		else if(Admin[playerid][LevelAdminX] == 2){

		    format(_Str, sizeof(_Str), "| CL-Admin | A Conta %s foi vinculada com sucesso para conta Administrativa nível Moderador", Nome);
		    SendClientMessage(playerid, -1, _Str);
		}
		else if(Admin[playerid][LevelAdminX] == 3){

		    format(_Str, sizeof(_Str), "| CL-Admin | A Conta %s foi vinculada com sucesso para conta Administrativa nível Administrador", Nome);
		    SendClientMessage(playerid, -1, _Str);
		}
		else if(Admin[playerid][LevelAdminX] == 4){

		    format(_Str, sizeof(_Str), "| CL-Admin | A Conta %s foi vinculada com sucesso para conta Administrativa nível Staff", Nome);
		    SendClientMessage(playerid, -1, _Str);
		}

		ShowPlayerDialog(playerid, SENHAADMIN, DIALOG_STYLE_PASSWORD, "Autenticacao", "Bem Vindo novamente ao City Of Life!\n\nO Sistema identificou o tipo de conta protegida, por esse motivo, autentique-se abaixo com a Senha Especial!\n\nFoi um engano? Vá ao forum imediatamente, pois o mal uso desse painel resultará em bloqueio de conta! ", "Autenticar", "");
	}
}
forward _OnPlayerConnect(playerid);
public _OnPlayerConnect(playerid){
	return 1;
}

forward _OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
public _OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]){
	return 1;
}

// INICIO DOS CMDs

CMD:explodir(playerid, params[]){
    if(Admin[playerid][LevelAdminX] >= 2){
		new
			Txd[256],
			_Var[128]
		;
		if(!IsPlayerConnected(ID))
			return SendClientMessage(playerid, -1, "| ERRO | O(A) Jogador(a) não está conectado(a) no servidor!");

		if(ID == playerid)
			return SendClientMessage(playerid, -1, "| ERRO | O ID inserido corresponde ao seu, insira um corretamente!");

		if(sscanf(params, "u", ID)){
		    SendClientMessage(playerid, -1, "| ERRO | Formato de Comando Inválido (FCI)! Modo Correto: /explodir [ ID do Jogador ]");
		} else {

		    format(Txd, sizeof(Txd), "| CL-RP | O(A) Administrador(a) explodiu você! Caso seja um engano, a administração pede desculpas pelo ocorrido!");
		    SendClientMessage(ID, -1, Txd);

		    format(_Var, sizeof(_Var), "| CL-RP | Você explodiu o jogador de ID %d!", ID);
		    SendClientMessage(playerid, -1, Txd);

		    new Float:x, Float:y, Float:z;
		    GetPlayerPos(ID, x, y, z);

		    CreateExplosion(x, y, z, 12, 10.0);
		}
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
		if(Admin[playerid][LevelAdminX] >= 1){
		    if(!IsPlayerConnected(ID))
				return SendClientMessage(playerid, -1, "| ERRO | O(A) Jogador(a) não está conectado(a) no servidor!");

		    if(ID == playerid)
		        return SendClientMessage(playerid, -1, "| ERRO | O ID inserido corresponde ao seu, insira um corretamente!");

			GetPlayerPos(ID, pX, pY, pZ); // Pos Player

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

CMD:trazer(playerid, params[]){

	new Str[128],
	    Str2[128],
		AdminQual[MAX_PLAYER_NAME],
		PlayerQual[MAX_PLAYER_NAME]
	;

	new
	    Float:aX,
        Float:aY,
        Float:aZ
	;

	if(sscanf(params, "u", ID)){
	    SendClientMessage(playerid, -1, "| ERRO | /ir [ID]");

	} else {
		if(Admin[playerid][LevelAdminX] >= 1){
		    if(!IsPlayerConnected(ID))
				return SendClientMessage(playerid, -1, "| ERRO | O(A) Jogador(a) não está conectado(a) no servidor!");

		    if(ID == playerid)
		        return SendClientMessage(playerid, -1, "| ERRO | O ID inserido corresponde ao seu, insira um corretamente!");

			GetPlayerPos(playerid, aX, aY, aZ); // Pos Admin

			GetPlayerName(ID, AdminQual, sizeof(AdminQual));
			GetPlayerName(playerid, PlayerQual, sizeof(PlayerQual));

			SetPlayerPos(ID, aX, aY, aZ);
            SetPlayerVirtualWorld(ID, GetPlayerVirtualWorld(playerid));
            SetPlayerInterior(ID, GetPlayerInterior(playerid));

			format(Str, sizeof(Str), "| CL-RP | Você trouxe o(a) jogador(a) %s até você!", AdminQual);
			format(Str2, sizeof(Str2), "| CL-RP | Você foi teleportado até o(a) Administrador(a) %s", PlayerQual);

			SendClientMessage(playerid, -1, Str);
			SendClientMessage(ID, -1, Str2);

		}
	}
	return 1;
}
