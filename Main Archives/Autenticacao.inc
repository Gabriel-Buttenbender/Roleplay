#include a_samp
#include DOF2

#define BoxLogar 1
#define BoxRegistrar 2

enum Jogador{
	Level,
	Dinheiro,
	Experiencia,
	Senha
}; new Player[MAX_PLAYERS][Jogador];

forward VerificarConta(playerid);

public VerificarConta(playerid){
	new _Var[128], Nome[MAX_PLAYER_NAME];
	
	GetPlayerName(playerid, Nome, sizeof(Nome));
	
	format(_Var, sizeof(_Var), ".../Banco de Dados/Cadastros/%s.ini", Nome);
	
	if(DOF2_FileExists(_Var)) ShowPlayerDialog(playerid, BoxLogar, DIALOG_STYLE_PASSWORD, "Logar no *****", "ALTERAR TEXTO BOX LOGAR", "Logar", "Cancelar");
	else ShowPlayerDialog(playerid, BoxRegistrar, DIALOG_STYLE_PASSWORD, "Logar no *****", "ALTERAR TEXTO BOX REGISTRAR", "Registrar", "Cancelar");

	return 1;
}

new ErrosConta[MAX_PLAYERS] = 0;

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]){
	new _Var[128], Nome[MAX_PLAYER_NAME];

	GetPlayerName(playerid, Nome, sizeof(Nome));

	format(_Var, sizeof(_Var), ".../Banco de Dados/Cadastros/%s.ini", Nome);
	
	if(dialogid == BoxLogar){
	    if(!response) Kick(playerid);
	
	    if(!strcmp(inputtext, DOF2_GetString(_Var, "Senha"), false)){
			Player[playerid][Level] = DOF2_GetInt(_Var, "Level");
			Player[playerid][Dinheiro] = DOF2_GetInt(_Var, "Dinheiro");
			Player[playerid][Experiencia] = DOF2_GetInt(_Var, "Experiencia");
			
			SendClientMessage(playerid, -1, "| INFO | Você se autenticou com sucesso no sistema!");

			SpawnPlayer(playerid);
			
			ErrosConta[playerid] = 0;
	    } else {
	        if(ErrosConta[playerid] >= 3) return Kick(playerid), ErrosConta[playerid] = 0;
	        
	        ErrosConta[playerid] ++;
	        SendClientMessage(playerid, -1, "| INFO | Você errou sua senha, caso erre 3 vezes será kickado!");
	    }
	    return 1;
 	}
 	if(dialogid == BoxRegistrar){
 	    if(!response) return 1;

	    DOF2_CreateFile(_Var);

		DOF2_SetString(_Var, "Senha", inputtext);
		
		DOF2_SetInt(_Var, "Level", 0);
		DOF2_SetInt(_Var, "Dinheiro", 100);
		DOF2_SetInt(_Var, "Experiencia", 0);

		DOF2_SaveFile();

        SendClientMessage(playerid, -1, "| INFO | Sua Conta foi cadastrada com sucesso no banco de dados!");

        ShowPlayerDialog(playerid, BoxLogar, DIALOG_STYLE_PASSWORD, "Logar no *****", "ALTERAR TEXTO BOX LOGAR", "Logar", "Cancelar");

	}
	return 1;
}