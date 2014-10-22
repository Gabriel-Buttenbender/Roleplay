#include a_samp
#include DOF2

#define BoxLogar 1
#define BoxRegistrar 2
#define BoxTutorial 3
#define BoxContato 4
#define BoxRecuperar 5

enum Jogador{
	Level,
	Dinheiro,
	Experiencia,
	Senha,
	Email
}; new Player[MAX_PLAYERS][Jogador];

new PlayerText:Textdraw0;
new PlayerText:Textdraw1;
new PlayerText:Textdraw2;
new PlayerText:Textdraw3;
new PlayerText:Textdraw4;
new PlayerText:Textdraw5;
new PlayerText:Textdraw6;
new PlayerText:Textdraw7;
new PlayerText:Textdraw8;
new PlayerText:Textdraw9;
new PlayerText:Textdraw10;
new PlayerText:Textdraw11;
new PlayerText:Textdraw12;
new PlayerText:Textdraw13;
new PlayerText:Textdraw14;
new PlayerText:Textdraw15;
new PlayerText:Textdraw16;

new TimeMSGmenu;

forward _OnPlayerDisconnect(playerid, reason);

public _OnPlayerDisconnect(playerid, reason){

	new _Var[128], Nome[MAX_PLAYER_NAME];

	GetPlayerName(playerid, Nome, sizeof(Nome));

	format(_Var, sizeof(_Var), "Dados/Cadastros/%s.ini", Nome);

	DOF2_SetInt(_Var, "Level", GetPlayerScore(playerid));
	DOF2_SetInt(_Var, "Dinheiro", GetPlayerMoney(playerid));
	DOF2_SetInt(_Var, "Experiencia", Player[playerid][Experiencia]);
	DOF2_SetString(_Var, "Email", Player[playerid][Email]);

	DOF2_SaveFile();

	return 1;
}

forward _OnPlayerRequestClass(playerid, classid);

public _OnPlayerRequestClass(playerid, classid){
    TXDlogin(playerid);

    PlayerTextDrawShow(playerid, Textdraw0);
    PlayerTextDrawShow(playerid, Textdraw1);
    PlayerTextDrawShow(playerid, Textdraw2);
    PlayerTextDrawShow(playerid, Textdraw3);
    PlayerTextDrawShow(playerid, Textdraw4);
    PlayerTextDrawShow(playerid, Textdraw5);
    PlayerTextDrawShow(playerid, Textdraw6);
    PlayerTextDrawShow(playerid, Textdraw7);
    PlayerTextDrawShow(playerid, Textdraw8);
    PlayerTextDrawShow(playerid, Textdraw9);
    PlayerTextDrawShow(playerid, Textdraw10);
    PlayerTextDrawShow(playerid, Textdraw11);
    PlayerTextDrawShow(playerid, Textdraw12);
    PlayerTextDrawShow(playerid, Textdraw13);
    PlayerTextDrawShow(playerid, Textdraw14);
    PlayerTextDrawShow(playerid, Textdraw15);
    PlayerTextDrawShow(playerid, Textdraw16);

    SelectTextDraw(playerid, -1);
	return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == Textdraw2) {
         ShowPlayerDialog(playerid, BoxLogar, DIALOG_STYLE_PASSWORD, "Logar no City Of Life", "{BEBEBE}Bem Vindo novamente ao {}City Of Life!\n\n", "Logar", "Cancelar");
         //CancelSelectTextDraw(playerid);
    }
    else if(playertextid == Textdraw5){
    	ShowPlayerDialog(playerid, BoxRegistrar, DIALOG_STYLE_PASSWORD, "Registrar no City Of Life", "ALTERAR TEXTO BOX REGISTRAR", "Registrar", "Cancelar");
        //CancelSelectTextDraw(playerid);
    }
    else if(playertextid == Textdraw8){
    	ShowPlayerDialog(playerid, BoxTutorial, DIALOG_STYLE_MSGBOX, "#TUTORIAL", "NÃO FEITO AINDA!", "---", "---");
       // CancelSelectTextDraw(playerid);
    }
    else if(playertextid == Textdraw11){
    	ShowPlayerDialog(playerid, BoxContato, DIALOG_STYLE_MSGBOX, "{BEBEBE}Contatos!", "{BEBEBE}Os contatos do servidor são sempre mantidos online, porém nem sempre isso é possível.\n\n{FA8072}Site: {BEBEBE}www.site.com.br\n{FA8072}Forum: {BEBEBE}www.site.com.br/forum\n{FA8072}TeamSpeak: {BEBEBE}000.000.000:0000\n\n{FFD700}Caso haja alguma dúvida sobre algum dos contatos procure um administrado!", "Fechar", "");
        //CancelSelectTextDraw(playerid);
    }
    else if(playertextid == Textdraw14){
    	ShowPlayerDialog(playerid, BoxRecuperar, DIALOG_STYLE_INPUT, "{BEBEBE}Recuperar Conta!", "{FA8072}Painel de Recuperação de Conta {FFD700}(PRC){BEBEBE}!\n\nPara recuperar a sua conta perdida/roubada, digite abaixo o email cadastrado na conta, ele deverá ser escrito corretamente.\n\n{1E90FF}O Servidor não se responsabiliza por roubo de contas, você deverá saber cuidar dela e jamais passa-la á estranhos!", "Enviar", "Fechar");
        //CancelSelectTextDraw(playerid);
    }
    return 1;
}

forward TXDlogin(playerid);

public TXDlogin(playerid){
	Textdraw0 = CreatePlayerTextDraw(playerid,642.000000, 2.000000, "_");
	PlayerTextDrawBackgroundColor(playerid,Textdraw0, 255);
	PlayerTextDrawFont(playerid,Textdraw0, 1);
	PlayerTextDrawLetterSize(playerid,Textdraw0, 0.500000, 2.599999);
	PlayerTextDrawColor(playerid,Textdraw0, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw0, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw0, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw0, 1);
	PlayerTextDrawUseBox(playerid,Textdraw0, 1);
	PlayerTextDrawBoxColor(playerid,Textdraw0, 255);
	PlayerTextDrawTextSize(playerid,Textdraw0, -11.000000, 0.000000);
	PlayerTextDrawSetSelectable(playerid,Textdraw0, 0);

	Textdraw1 = CreatePlayerTextDraw(playerid,67.000000, 3.000000, "_");
	PlayerTextDrawBackgroundColor(playerid,Textdraw1, 255);
	PlayerTextDrawFont(playerid,Textdraw1, 1);
	PlayerTextDrawLetterSize(playerid,Textdraw1, 0.500000, 2.200000);
	PlayerTextDrawColor(playerid,Textdraw1, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw1, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw1, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw1, 1);
	PlayerTextDrawUseBox(playerid,Textdraw1, 1);
	PlayerTextDrawBoxColor(playerid,Textdraw1, -1094795521);
	PlayerTextDrawTextSize(playerid,Textdraw1, 5.000000, 0.000000);
	PlayerTextDrawSetSelectable(playerid,Textdraw1, 0);

	Textdraw2 = CreatePlayerTextDraw(playerid,15.000000, 1.000000, "LOGAR");
	PlayerTextDrawBackgroundColor(playerid,Textdraw2, 255);
	PlayerTextDrawFont(playerid,Textdraw2, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw2, 0.310000, 1.400000);
	PlayerTextDrawColor(playerid,Textdraw2, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw2, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw2, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw2, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw2, 1);
	PlayerTextDrawTextSize(playerid, Textdraw2, 586.000000, 10.000000);

	Textdraw3 = CreatePlayerTextDraw(playerid,17.000000, 13.000000, "No Servidor");
	PlayerTextDrawBackgroundColor(playerid,Textdraw3, 255);
	PlayerTextDrawFont(playerid,Textdraw3, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw3, 0.140000, 1.100000);
	PlayerTextDrawColor(playerid,Textdraw3, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw3, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw3, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw3, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw3, 0);

	Textdraw4 = CreatePlayerTextDraw(playerid,129.000000, 3.000000, "_");
	PlayerTextDrawBackgroundColor(playerid,Textdraw4, 255);
	PlayerTextDrawFont(playerid,Textdraw4, 1);
	PlayerTextDrawLetterSize(playerid,Textdraw4, 0.500000, 2.200000);
	PlayerTextDrawColor(playerid,Textdraw4, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw4, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw4, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw4, 1);
	PlayerTextDrawUseBox(playerid,Textdraw4, 1);
	PlayerTextDrawBoxColor(playerid,Textdraw4, -1094795521);
	PlayerTextDrawTextSize(playerid,Textdraw4, 66.000000, -6.000000);
	PlayerTextDrawSetSelectable(playerid,Textdraw4, 0);

	Textdraw5 = CreatePlayerTextDraw(playerid,74.000000, 1.000000, "REGISTRAR");
	PlayerTextDrawBackgroundColor(playerid,Textdraw5, 255);
	PlayerTextDrawFont(playerid,Textdraw5, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw5, 0.210000, 1.500000);
	PlayerTextDrawColor(playerid,Textdraw5, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw5, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw5, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw5, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw5, 1);

	Textdraw6 = CreatePlayerTextDraw(playerid,77.000000, 13.000000, "No Servidor");
	PlayerTextDrawBackgroundColor(playerid,Textdraw6, 255);
	PlayerTextDrawFont(playerid,Textdraw6, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw6, 0.140000, 1.100000);
	PlayerTextDrawColor(playerid,Textdraw6, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw6, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw6, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw6, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw6, 0);

	Textdraw7 = CreatePlayerTextDraw(playerid,188.000000, 4.000000, "_");
	PlayerTextDrawBackgroundColor(playerid,Textdraw7, 255);
	PlayerTextDrawFont(playerid,Textdraw7, 1);
	PlayerTextDrawLetterSize(playerid,Textdraw7, 0.500000, 2.100000);
	PlayerTextDrawColor(playerid,Textdraw7, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw7, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw7, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw7, 1);
	PlayerTextDrawUseBox(playerid,Textdraw7, 1);
	PlayerTextDrawBoxColor(playerid,Textdraw7, -1094795521);
	PlayerTextDrawTextSize(playerid,Textdraw7, 128.000000, -8.000000);
	PlayerTextDrawSetSelectable(playerid,Textdraw7, 0);

	Textdraw8 = CreatePlayerTextDraw(playerid,133.000000, 2.000000, "TUTORIAL");
	PlayerTextDrawBackgroundColor(playerid,Textdraw8, 255);
	PlayerTextDrawFont(playerid,Textdraw8, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw8, 0.250000, 1.400000);
	PlayerTextDrawColor(playerid,Textdraw8, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw8, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw8, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw8, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw8, 1);

	Textdraw9 = CreatePlayerTextDraw(playerid,134.000000, 13.000000, "( Iniciantes )");
	PlayerTextDrawBackgroundColor(playerid,Textdraw9, 255);
	PlayerTextDrawFont(playerid,Textdraw9, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw9, 0.170000, 1.100000);
	PlayerTextDrawColor(playerid,Textdraw9, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw9, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw9, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw9, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw9, 0);

	Textdraw10 = CreatePlayerTextDraw(playerid,249.000000, 4.000000, "_");
	PlayerTextDrawBackgroundColor(playerid,Textdraw10, 255);
	PlayerTextDrawFont(playerid,Textdraw10, 1);
	PlayerTextDrawLetterSize(playerid,Textdraw10, 0.500000, 2.100000);
	PlayerTextDrawColor(playerid,Textdraw10, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw10, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw10, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw10, 1);
	PlayerTextDrawUseBox(playerid,Textdraw10, 1);
	PlayerTextDrawBoxColor(playerid,Textdraw10, -1094795521);
	PlayerTextDrawTextSize(playerid,Textdraw10, 187.000000, 12.000000);
	PlayerTextDrawSetSelectable(playerid,Textdraw10, 0);

	Textdraw11 = CreatePlayerTextDraw(playerid,193.000000, 1.000000, "CONTATOS");
	PlayerTextDrawBackgroundColor(playerid,Textdraw11, 255);
	PlayerTextDrawFont(playerid,Textdraw11, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw11, 0.230000, 1.500000);
	PlayerTextDrawColor(playerid,Textdraw11, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw11, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw11, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw11, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw11, 1);

	Textdraw12 = CreatePlayerTextDraw(playerid,198.000000, 13.000000, "SITE E FORUM");
	PlayerTextDrawBackgroundColor(playerid,Textdraw12, 255);
	PlayerTextDrawFont(playerid,Textdraw12, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw12, 0.140000, 1.200000);
	PlayerTextDrawColor(playerid,Textdraw12, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw12, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw12, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw12, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw12, 0);

	Textdraw13 = CreatePlayerTextDraw(playerid,306.000000, 4.000000, "_");
	PlayerTextDrawBackgroundColor(playerid,Textdraw13, 255);
	PlayerTextDrawFont(playerid,Textdraw13, 1);
	PlayerTextDrawLetterSize(playerid,Textdraw13, 0.500000, 2.100000);
	PlayerTextDrawColor(playerid,Textdraw13, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw13, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw13, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw13, 1);
	PlayerTextDrawUseBox(playerid,Textdraw13, 1);
	PlayerTextDrawBoxColor(playerid,Textdraw13, -1094795521);
	PlayerTextDrawTextSize(playerid,Textdraw13, 248.000000, -1.000000);
	PlayerTextDrawSetSelectable(playerid,Textdraw13, 0);

	Textdraw14 = CreatePlayerTextDraw(playerid,251.000000, 1.000000, "RECUPERAR");
	PlayerTextDrawBackgroundColor(playerid,Textdraw14, 255);
	PlayerTextDrawFont(playerid,Textdraw14, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw14, 0.220000, 1.600000);
	PlayerTextDrawColor(playerid,Textdraw14, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw14, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw14, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw14, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw14, 1);

	Textdraw15 = CreatePlayerTextDraw(playerid,252.000000, 13.000000, "Conta e Dados");
	PlayerTextDrawBackgroundColor(playerid,Textdraw15, 255);
	PlayerTextDrawFont(playerid,Textdraw15, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw15, 0.149999, 1.200000);
	PlayerTextDrawColor(playerid,Textdraw15, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw15, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw15, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw15, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw15, 0);

	Textdraw16 = CreatePlayerTextDraw(playerid,308.000000, 7.000000, "City Of Life - RolePlay");
	PlayerTextDrawBackgroundColor(playerid,Textdraw16, 255);
	PlayerTextDrawFont(playerid,Textdraw16, 2);
	PlayerTextDrawLetterSize(playerid,Textdraw16, 0.370000, 1.299999);
	PlayerTextDrawColor(playerid,Textdraw16, -1);
	PlayerTextDrawSetOutline(playerid,Textdraw16, 0);
	PlayerTextDrawSetProportional(playerid,Textdraw16, 1);
	PlayerTextDrawSetShadow(playerid,Textdraw16, 1);
	PlayerTextDrawSetSelectable(playerid,Textdraw16, 0);

	TimeMSGmenu = SetTimerEx("TextDraw", 60, true, "i", playerid);

	for(new i; i < 100; i++){
	    SendClientMessage(playerid, -1, " ");
	}

	SendClientMessage(playerid, -1, "| MENU | Bem vindo ao menu principal! Use as opções do menu superior conforme suas necessidades!");
	return 1;
}

new ErrosConta[MAX_PLAYERS] = 0;

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]){
	if(dialogid == BoxLogar){

	    if(!response) return SelectTextDraw(playerid, -1);

		new _Var[128], Nome[MAX_PLAYER_NAME];

		GetPlayerName(playerid, Nome, sizeof(Nome));

		format(_Var, sizeof(_Var), "Dados/Cadastros/%s.ini", Nome);

		if(strlen(inputtext) < 3 || strlen(inputtext) > 24) return
		    SelectTextDraw(playerid, -1), SendClientMessage(playerid, -1, "| INFO | Os digitos de senha permitidos pelo servidor não se igualam nestes digitados!");

		if(!DOF2_FileExists(_Var))
		    return SelectTextDraw(playerid, -1), SelectTextDraw(playerid, -1), SendClientMessage(playerid, -1, "| INFO | O Sistema não encontrou sua conta no banco de dados, crie uma para poder jogar!");

	    if(!strcmp(inputtext, DOF2_GetString(_Var, "Senha"), false)){
			Player[playerid][Level] = DOF2_GetInt(_Var, "Level");
			Player[playerid][Dinheiro] = DOF2_GetInt(_Var, "Dinheiro");
			Player[playerid][Experiencia] = DOF2_GetInt(_Var, "Experiencia");

			SendClientMessage(playerid, -1, "| INFO | Você se autenticou com sucesso no sistema!");

            SpawnPlayer(playerid);
            SetPlayerPos(playerid, 1834.80017, -1311.05750, 114.80832);

			PlayerTextDrawHide(playerid, Textdraw0);
			PlayerTextDrawHide(playerid, Textdraw1);
			PlayerTextDrawHide(playerid, Textdraw2);
			PlayerTextDrawHide(playerid, Textdraw3);
			PlayerTextDrawHide(playerid, Textdraw4);
			PlayerTextDrawHide(playerid, Textdraw5);
			PlayerTextDrawHide(playerid, Textdraw6);
			PlayerTextDrawHide(playerid, Textdraw7);
			PlayerTextDrawHide(playerid, Textdraw8);
			PlayerTextDrawHide(playerid, Textdraw9);
			PlayerTextDrawHide(playerid, Textdraw10);
			PlayerTextDrawHide(playerid, Textdraw11);
			PlayerTextDrawHide(playerid, Textdraw12);
			PlayerTextDrawHide(playerid, Textdraw13);
			PlayerTextDrawHide(playerid, Textdraw14);
			PlayerTextDrawHide(playerid, Textdraw15);
			PlayerTextDrawHide(playerid, Textdraw16);

			KillTimer(TimeMSGmenu);
			
			CancelSelectTextDraw(playerid);

			ErrosConta[playerid] = 0;
	    	} else {
   	  		if(ErrosConta[playerid] >= 3) return Kick(playerid), ErrosConta[playerid] = 0;

	        ErrosConta[playerid] ++;
	        SendClientMessage(playerid, -1, "| INFO | Você errou sua senha, caso erre 3 vezes será kickado!");
	        SelectTextDraw(playerid, -1);
	    }
	    return 1;
 	}
 	if(dialogid == BoxRegistrar){
 	    if(!response) return SelectTextDraw(playerid, -1);

		new _Var[128], Nome[MAX_PLAYER_NAME];

		GetPlayerName(playerid, Nome, sizeof(Nome));

		format(_Var, sizeof(_Var), "Dados/Cadastros/%s.ini", Nome);


  		if(strlen(inputtext) < 3 || strlen(inputtext) > 24)
		    SendClientMessage(playerid, -1, "| INFO | É Necessário que sua senha seja maior que 3 digitou e menor que 24 digitos!"),
            ShowPlayerDialog(playerid, BoxRegistrar, DIALOG_STYLE_PASSWORD, "Registrar no City Of Life", "ALTERAR TEXTO BOX REGISTRAR", "Registrar", "Cancelar")
			;

		if(DOF2_FileExists(_Var))
		    return SendClientMessage(playerid, -1, "| INFO | O Sistema encontrou sua conta no banco de dados, logue para jogar!"),
			SelectTextDraw(playerid, -1);

	    DOF2_CreateFile(_Var);

		DOF2_SetString(_Var, "Senha", inputtext);

		DOF2_SetInt(_Var, "Level", 0);
		DOF2_SetInt(_Var, "Dinheiro", 100);
		DOF2_SetInt(_Var, "Experiencia", 0);
		DOF2_SetString(_Var, "Email", "Email não Cadastrado");

		DOF2_SaveFile();

        SendClientMessage(playerid, -1, "| INFO | Sua Conta foi cadastrada com sucesso no banco de dados!");
        SendClientMessage(playerid, -1, "| INFO | Use a opção Logar no menu superior para logar no servidor!");

        SelectTextDraw(playerid, -1);

	}
	return 1;
}

new Shady91;

forward TextDraw(playerid);
public TextDraw(playerid)
{
        Shady91++;
        if(Shady91 == 1)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "ay");
        }
        if(Shady91 == 2)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "lePlay");
        }
        if(Shady91 == 3)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "olePlay");
        }
        if(Shady91 == 4)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "RolePlay");
        }
        if(Shady91 == 5)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "e - RolePlay");
        }
        if(Shady91 == 6)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "fe - RolePlay");
        }
        if(Shady91 == 7)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "ife - RolePlay");
        }
        if(Shady91 == 8)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "Life - RolePlay");
        }
        if(Shady91 == 9)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "f Life - RolePlay");
        }
        if(Shady91 == 10)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "Of Life - RolePlay");
        }
        if(Shady91 == 11)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "y Of Life - RolePlay");
        }
        if(Shady91 == 12)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "ty Of Life - RolePlay");
        }
        if(Shady91 == 13)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "ity Of Life - RolePlay");
        }
        if(Shady91 == 14)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "City Of Life - RolePlay");
        }
        if(Shady91 == 15)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, " City Of Life - RolePlay");
        }
        if(Shady91 == 16)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "  City Of Life - RolePlay");
        }
        if(Shady91 == 17)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "   City Of Life - RolePlay");
        }
        if(Shady91 == 18)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "    City Of Life - RolePlay");
        }
        if(Shady91 == 19)
        {// pugs the next level rpg v1.5a
                PlayerTextDrawSetString(playerid, Textdraw16, "     City Of Life - RolePlay");
        }
        if(Shady91 == 20)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "      City Of Life - RolePlay");
        }
        if(Shady91 == 21)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "       City Of Life - RolePlay");
        }
        if(Shady91 == 22)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "        City Of Life - RolePlay");
        }
        if(Shady91 == 23)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "         City Of Life - RolePlay");
        }
        if(Shady91 == 24)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "          City Of Life - RolePlay");
        }
        if(Shady91 == 25)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "           City Of Life - RolePlay");
        }
        if(Shady91 == 26)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "            City Of Life - RolePlay");
        }
        if(Shady91 == 27)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "             City Of Life - RolePlay");
        }
        if(Shady91 == 28)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "              City Of Life - RolePlay");
        }
        if(Shady91 == 29)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "               City Of Life - RolePlay");
        }
        if(Shady91 == 30)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                 City Of Life - RolePlay");
        }
        if(Shady91 == 31)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                  City Of Life - RolePlay");
        }
        if(Shady91 == 32)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                   City Of Life - RolePlay");
        }
        if(Shady91 == 33)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                    City Of Life - RolePlay");
        }
        if(Shady91 == 34)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                     City Of Life - RolePlay");
        }
        if(Shady91 == 35)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                      City Of Life - RolePlay");
        }
        if(Shady91 == 36)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                       City Of Life - RolePlay");
        }
        if(Shady91 == 37)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                        City Of Life - RolePlay");
        }
        if(Shady91 == 38)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                         City Of Life - RolePlay");
        }
        if(Shady91 == 39)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                          City Of Life - RolePlay");
        }
        if(Shady91 == 40)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                           City Of Life - RolePlay");
        }
        if(Shady91 == 41)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                            City Of Life - RolePlay");
        }
        if(Shady91 == 42)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                             City Of Life - RolePlay");
        }
        if(Shady91 == 43)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                              City Of Life - RolePlay");
        }
        if(Shady91 == 44)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                               City Of Life - RolePlay");
        }
        if(Shady91 == 45)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                City Of Life - RolePlay");
        }
        if(Shady91 == 46)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                 City Of Life - RolePlay");
        }
        if(Shady91 == 46)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                  City Of Life - RolePlay");
        }
        if(Shady91 == 47)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                   City Of Life - RolePlay");
        }
        if(Shady91 == 48)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                    City Of Life - RolePlay");
        }
        if(Shady91 == 49)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                     City Of Life - RolePlay");
        }
        if(Shady91 == 50)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                      City Of Life - RolePlay");
        }
        if(Shady91 == 51)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                       City Of Life - RolePlay");
        }
        if(Shady91 == 52)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                        City Of Life - RolePlay");
        }
        if(Shady91 == 53)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                         City Of Life - RolePlay");
        }
        if(Shady91 == 54)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                          City Of Life - RolePlay");
        }
        if(Shady91 == 55)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                           City Of Life - RolePlay");
        }
        if(Shady91 == 56)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                            City Of Life - RolePlay");
        }
        if(Shady91 == 57)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                             City Of Life - RolePlay");
        }
        if(Shady91 == 58)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                              City Of Life - RolePlay");
        }
        if(Shady91 == 59)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                               City Of Life - RolePlay");
        }
        if(Shady91 == 60)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                City Of Life - RolePlay");
        }
        if(Shady91 == 61)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                 City Of Life - RolePlay");
        }
        if(Shady91 == 62)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                  City Of Life - RolePlay");
        }
        if(Shady91 == 63)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                   City Of Life - RolePlay");
        }
        if(Shady91 == 64)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                    City Of Life - RolePlay");
        }
        if(Shady91 == 65)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                     City Of Life - RolePlay");
        }
        if(Shady91 == 66)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                      City Of Life - RolePlay");
        }
        if(Shady91 == 67)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                       City Of Life - RolePlay");
        }
        if(Shady91 == 68)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                        City Of Life - RolePlay");
        }
        if(Shady91 == 69)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                         City Of Life - RolePlay");
        }
        if(Shady91 == 70)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                          City Of Life - RolePlay");
        }
        if(Shady91 == 71)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                           City Of Life - RolePlay");
        }
        if(Shady91 == 72)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                            City Of Life - RolePlay");
        }
        if(Shady91 == 73)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                             City Of Life - RolePlay");
        }
        if(Shady91 == 74)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                             City Of Life - RolePlay");
        }
        if(Shady91 == 75)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                              City Of Life - RolePlay");
        }
        if(Shady91 == 76)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                               City Of Life - RolePlay");
        }
        if(Shady91 == 77)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                City Of Life - RolePlay");
        }
        if(Shady91 == 78)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                 City Of Life - RolePlay");
        }
        if(Shady91 == 79)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                  City Of Life - RolePlay");
        }
        if(Shady91 == 80)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                   City Of Life - RolePlay");
        }
        if(Shady91 == 81)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                    City Of Life - RolePlay");
        }
        if(Shady91 == 82)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                     City Of Life - RolePlay");
        }
        if(Shady91 == 83)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                      City Of Life - RolePlay");
        }
        if(Shady91 == 84)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                       City Of Life - RolePlay");
        }
        if(Shady91 == 85)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                        City Of Life - RolePlay");
        }
        if(Shady91 == 86)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                         City Of Life - RolePlay");
        }
        if(Shady91 == 87)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                          City Of Life - RolePlay");
        }
        if(Shady91 == 88)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                           City Of Life - RolePlay");
        }
        if(Shady91 == 89)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                            City Of Life - RolePlay");
        }
        if(Shady91 == 90)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                             City Of Life - RolePlay");
        }
        if(Shady91 == 91)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                              City Of Life - RolePlay");
        }
        if(Shady91 == 92)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                               City Of Life - RolePlay");
        }
        if(Shady91 == 93)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                City Of Life - RolePlay");
        }
        if(Shady91 == 94)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                 City Of Life - RolePlay");
        }
        if(Shady91 == 95)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                  City Of Life - RolePlay");
        }
        if(Shady91 == 96)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                   City Of Life - RolePlay");
        }
        if(Shady91 == 97)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                    City Of Life - RolePlay");
        }
        if(Shady91 == 98)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                     City Of Life - RolePlay");
        }
        if(Shady91 == 99)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                      City Of Life - RolePlay");
        }
        if(Shady91 == 100)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                       City Of Life - RolePlay");
        }
        if(Shady91 == 101)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                        City Of Life - RolePlay");
        }
        if(Shady91 == 102)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                         City Of Life - RolePlay");
        }
        if(Shady91 == 103)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                          City Of Life - RolePlay");
        }
        if(Shady91 == 104)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                           City Of Life - RolePlay");
        }
        if(Shady91 == 105)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                            City Of Life - RolePlay");
        }
        if(Shady91 == 106)
        {
                PlayerTextDrawSetString(playerid, Textdraw16, "                                                                                             City Of Life - RolePlay");
                Shady91 = -5;
        }
        return 1;
}