#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



void menu(void){
	int escolha;
	
	printf("Seja bem vindo ao RPG\n");
	printf("1 - Jogar.\n2 - Sair.\n");
	scanf("%d",&escolha);
	if(escolha == 1){
		system("cls");
		fichaPersonagem();
	}else{
		return 0;
	}
}



void fichaPersonagem(void){
	
	char personagem[30];
	int classe_tmp,classe=0;
	int hp,mana;
	int forca,destreza,inteligencia,armadura,agilidade,vontade,atrib=24,total_atrib,cust_hab,mana_atual,vida_atual;
	char habilidade[255];;
	int dano_hab,cust_mana;
	
	/*Nome do personagem*/
	printf("Digite o nome do seu personagem: ");
	scanf("%s",&personagem);
	printf("Nome: %s",personagem);
	
	printf("\n\nOla %s, voce sera teletransportado para Valhalla!", personagem);
	sleep(3);
	system("cls");
	/*Classe do personagem*/
	printf("Seja bem vindo a Valhalla, esta na hora de escolher a sua classe!\n");
	
	printf("Escolha entre:\n1-Ladino.\n2-Clerigo.\n3-Bardo.\n4-Barbaro.\n5-Arqueiro\n");
	scanf("%d",&classe_tmp);
	/*Enquanto a variavel classe for igual a 0, ele irá rodar a pergunta da classe*/
	while(classe==0){
		if(classe_tmp >=1 && classe_tmp <=5){
			classe = classe_tmp;
		
		}else{
			printf("Escolha entre:\n1-Ladino.\n2-Clerigo.\n3-Bardo.\n4-Barbaro.\n5-Arqueiro\n");
			scanf("%d",&classe_tmp);	
		}
	}
		
	
	switch(classe){
		case 1:
			printf("Voce escolheu ser Ladino.\n");
			printf("\nLadinos sao uma classe de ladroes furtivos e escorregadios.");
			cust_mana = 3;
			hp = 10;
			mana = 8;
			break;
		case 2:
			printf("Voce escolheu ser Clerigo.\n");
			printf("\nUm clérigo tem o poder de expulsar mortos-vivos, da mesma maneira que pode os invocar e os controlar para realizar seus objetivos.");
			cust_mana = 5;
			hp = 12;
			mana = 15;
			break;
		case 3:
			printf("Voce escolheu ser Bardo.\n");
			printf("\nBardos sao cantores e contadores de histórias natos. Geralmente sao bons músicos, seja na forma do canto ou das notas de seu instrumento ou ainda bons atores ou artistas plasticos.");
			cust_mana = 6;
			hp = 12;
			mana = 15;	
			break;
		case 4:
			printf("Voce escolheu ser Barbaro.\n");
			printf("\n Sao guerreiros de origem selvagem, geralmente derivados de tribos bárbaras em regioes distantes.");
			cust_mana = 2;
			hp = 20;
			mana = 6;
			break;
		case 5:
			printf("Voce escolheu ser Arqueiro.\n");
			printf("\nArqueiros podem ser considerados classe de apoio, assim como classe de combate a curta distancia.");
			cust_mana = 3;
			hp = 8;
			mana = 10;			
			break;
		default:
			break;
	}
	sleep(2);
	system("cls");
	/*Distribuição de pontos de atribuito*/
	printf("\nVoce tem 24 pontos de atributos para dividir entre:\n ");
	printf("\nForca, Destreza, Inteligencia, Armadura, Agilidade e Forca de Vontade\n");
	/*Enquanto o total de atributos colocados for diferente de 24, ele irá rodar até a pessoa distribuir corretamente*/
	while(total_atrib != atrib){
	
		printf("\nForca: ");
		scanf("%d",&forca);
		printf("\nDestreza: ");
		scanf("%d",&destreza);
		printf("\nInteligencia: ");
		scanf("%d",&inteligencia);
		printf("\nArmadura: ");
		scanf("%d",&armadura);
		printf("\nAgilidade: ");
		scanf("%d",&agilidade);
		printf("\nForca de Vontade: ");
		scanf("%d",&vontade);
		total_atrib = forca + destreza + inteligencia + armadura + agilidade + vontade;
		if(total_atrib > 24){
			printf("\nVoce passou do total de pontos! Faca novamente a distribuicao");
		}	
	}
	/*Ficha de personagem*/

	system("cls");
	printf("\t\t\tFicha de Personagem\n");
	printf("*********************************************************\n");
	printf("Nome do Personagem:%s ",personagem);
	printf("****** Vida: %d ****** Mana:%d",hp,mana);
	if(classe == 1){
		printf("\nClasse: Ladino ****** Habilidade: Empunhadura Dupla(%d de mana)",cust_mana);	
	}else if(classe == 2){
		printf("\nClasse: Clerigo ****** Habilidade: Bencao Divina(%d de mana)",cust_mana);	
	}else if(classe == 3){
		printf("\nClasse: Bardo ****** Habilidade: Danca Contagiante(%d de mana)",cust_mana);
	}else if(classe == 4){
		printf("\nClasse: Barbaro ****** Habilidade: Frenesi(%d de mana)",cust_mana);
	}else if(classe == 5){
		printf("\nClasse: Arqueiro ****** Habilidade: Chuva de Flechas(%d de mana)",cust_mana);
	}
	printf("\nAtributos");
	printf("\nForca: %d",forca);	
	printf("\nDestreza: %d",destreza);
	printf("\nInteligencia: %d",inteligencia);
	printf("\nArmadura: %d",armadura);
	printf("\nAgilidade: %d",agilidade);
	printf("\nForca de vontade: %d",vontade);	
	printf("\n*********************************************************");
	printf("\n\nVamos comecar a historia");
	sleep(8);
	system("cls");
	
	/*Inicio da aventura*/
//	int escolha_rota,voltar;
//	printf("Voce esta caminhando numa floresta querendo ir para o vilarejo mais proximo, quando de repente aparece dois caminhos diferentes.");
//	printf("\nVoce escolhe:\n 1- Ir para a direita.\n2- Ir para a esquerda");
	int escolha_rota,voltar,dado,escolha_dado,escolha_dado_fugir;
	int dano_causado;
	int hp_lider_ork=30,dano_lider_ork=15,armadura_lo=10,hp_atual_lo,hp_lider_lo;
	int hp_att =hp;
	int dado_lo;
	int escolha_rota_fd;
	printf("Voce esta caminhando numa floresta querendo ir para o vilarejo mais proximo, quando de repente aparece dois caminhos diferentes.");
	while(escolha_rota ==0 || escolha_rota > 2 || voltar == 1 || dado >=8){
		voltar = 0;
		
		printf("\nVoce escolhe:\n 1- Ir para a direita.\n2- Ir para a esquerda\n");
		scanf("%d",&escolha_rota);
		
		if(escolha_rota == 1){
		    
			printf("Uma fada aparece na sua frente!\n");
			printf("-Ola, eu sou Yennefer. Soube que voce quer chegar no vilarejo para descansar... Esse caminho e mais longo, venha comigo, vou lhe mostrar um atalho.");
			while(escolha_rota_fd==0 || escolha_rota_fd >2){
			    escolha_rota_fd==0;
			    printf("\n\nEscolha\n1-Seguir a fada e pegar o Atalho.\n2-Continuar seu caminho sozinho.");
			    scanf("%d",&escolha_rota_fd);
			    if(escolha_rota_fd ==1){
			        printf("\n-Tudo bem vamos, estou bastante cansado e não quero andar muito.");
			        printf("\nAndando um pouco mais voce ve que a fada esta lhe levando para uma emboscada.\n");
			        printf("Mas... percebe tarde demais e um Ork gigante aparece na sua frente, ele é o Lider Ork.\nVoce olha pro lado e a fada rindo desaparece...");
			        printf("\nVoce tera que lutar pela sua propria vida!");
			        while(escolha_dado !=1){
						    while(hp_lider_ork != 0 || hp != 0){
							    printf("\nDigite 1 para rolar o dado e tentar atacar!\n");
							    scanf("%d",&escolha_dado);
		                        if(escolha_dado == 1){
								    
								    
									dado = (1+rand()%10);
									printf("Voce tirou: %d\n",dado);
									/*Se o jogador tirar 6 a 9 - Ele acerta*/
									if(dado>=6 && dado<10){
									    dano_causado=forca*2;
									    hp_lider_ork=hp_lider_ork-dano_causado;
                                        printf("Causou %d de dano",dano_causado);
                                        printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
                                        if(hp_lider_ork <=0){
									        printf("\nVOCE MATOU O LIDER ORK!");
									        exit(0);
									    }
                                        printf("\nO Lider Ork irá atacar!");
                                        dado=0;
                                        
									    dado = (1+rand()%10);
									    printf("\nO Lider Ork tirou: %d\n",dado);
									    
									    if(dado>=6 && dado<10){
									       dano_causado=hp_att/2;
									        hp=hp-dano_causado;
									        printf("O Lider Ork causou %d de dano",dano_causado);
									        printf("\nSua vida atual é: %d",hp);
									        if(hp <=0){
									            printf("\nVoce morreu...");
									            exit(0);
									        }
									    }else if(dado == 10){
									        printf("O Lider Ork acertou no seu coracao e voce morreu...");
									        exit(0);
									        
									    }else if(dado <= 5){
									        printf("Voce conseguiu desviar!");
									    }else if(dado == 1){
									        printf("Na tentativa de ataque, o Lider Ork escorregou e caiu.");
									        dano_causado = forca*3;
									        hp_lider_ork=hp_lider_ork-dano_causado;
									        printf("\nVoce atacou e causou %d",dano_causado);
									        printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
									        if(hp_lider_ork <=0){
									            printf("\nVOCE MATOU O LIDER ORK!");
									            exit(0);
									        }
									        
									    }
                                        
									}/*Se o jogador tirar 10, ele tem um acerto critico*/
									else if(dado == 10){
									    printf("Voce perfurou o Lider Ork!");
									    dano_causado=forca*4;
									    hp_lider_ork=hp_lider_ork-dano_causado;
									    printf("\nVoce causou: %d",dano_causado);
									    printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
									    if(hp_lider_ork <=0){
									       printf("\nVOCE MATOU O LIDER ORK!");
									       exit(0);
									   }
									    printf("\nO Lider Ork irá atacar!");
                                        dado=0;
                                        
									    dado = (1+rand()%10);
									    printf("\nO Lider Ork tirou: %d\n",dado);
									    
									    if(dado>=6 && dado<10){
									       dano_causado=hp_att/2;
									        hp=hp-dano_causado;
									        printf("O Lider Ork causou %d de dano",dano_causado);
									        printf("\nSua vida atual é: %d",hp);
									        if(hp <=0){
									            printf("\nVoce morreu...");
									            exit(0);
									        }
									    }else if(dado == 10){
									        printf("O Lider Ork acertou no seu coracao e voce morreu...");
									        exit(0);
									        
									    }else if(dado <= 5){
									        printf("Voce conseguiu desviar!");
									    }else if(dado == 1){
									        printf("Na tentativa de ataque, o Lider Ork escorregou e caiu.");
									        dano_causado = forca*3;
									        hp_lider_ork=hp_lider_ork-dano_causado;
									        printf("\nVoce atacou e causou %d",dano_causado);
									        printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
									        if(hp_lider_ork <=0){
									            printf("\nVOCE MATOU O LIDER ORK!");
									            exit(0);
									        }
									    }
								    }/*Se o jogador tirar 5 a 2, ele erra*/
									else if(dado <= 5 && dado >1){
									    printf("Na tentativa de ataque, o Lider ork desviou e riu de voce!\n");
									    printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
                                        printf("\nO Lider Ork irá atacar!");
                                        
                                        dado=0;
									    dado = (1+rand()%10);
									    
									    printf("\nO Lider Ork tirou: %d\n",dado);
									    if(dado>=6 && dado<10){
									       dano_causado=hp_att/2;
									        hp=hp-dano_causado;
									        printf("O Lider Ork causou %d de dano",dano_causado);
									        printf("\nSua vida atual é: %d",hp);
									        if(hp <=0){
									            printf("\nVoce morreu...");
									            exit(0);
									        }
									    }else if(dado == 10){
									        printf("O Lider Ork acertou no seu coracao e voce morreu...");
									        exit(0);
									        
									    }else if(dado <= 5){
									        printf("Voce conseguiu desviar!");
									    }else if(dado == 1){
									        printf("Na tentativa de ataque, o Lider Ork escorregou e caiu;");
									        dano_causado = forca*3;
									        hp_lider_ork=hp_lider_ork-dano_causado;
									        printf("\nVoce atacou e causou %d",dano_causado);
									        printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
									        if(hp_lider_ork <=0){
									            printf("\nVOCE MATOU O LIDER ORK!");
									            exit(0);
									        }
									    }
                                    }/*Se o jogador tirar 1, ele tem um erro critico e o Monstro ataca direto*/
									else if(dado == 1){
									    printf("Na hora de tentar atacar, o Lider ork desviou e lhe deu um chute!\n");
									    dano_causado = hp_att/2 + 1;
									    hp=hp-dano_causado;
									    printf("O Lider Ork causou %d de dano",dano_causado);
									    if(hp <=0){
									       printf("\nVoce morreu...");
									       exit(0);
									    }
									}
									hp=hp;
									dado =1;
									hp_lider_ork=hp_lider_ork;
								}
							}
						}
			     
		        }else if(escolha_rota_fd==2){
			        printf("\n-Não obrigado, prefiro seguir meu caminho sozinho do que confiar em uma fada.");
			        printf("\nVoce deixa a fada para tras e continua seu caminho.\n");
			        printf("Horas depois de tanto caminhar, voce chega no vilarejo, um vilarejo cheio de arvores e casinhas pequenas.");
			        exit(0);
			    }else{
			        printf("\nEscolha uma opção Valida!");
			    }
			 }
		}else if(escolha_rota == 2){
			printf("Voce encontra um ork morto no chao e uma parede de arbusto pouco depois dele");
			while(voltar >2 || voltar <1){
			    printf("\n Voce:\n1-Volta.\n2-Passa pelo arbusto\n");
			    scanf("%d",&voltar);
			}
			if(voltar == 2){
				printf("Voce se depara com o lider ork furioso por voce ter entrado no territorio dele!");
				dado =0;
				escolha_dado_fugir = 0;
				while(dado < 1){
				    while(escolha_dado_fugir != 1){
					    printf("\nDigite 1 e role o dado para tentar fugir.\n");
					    scanf("%d",&escolha_dado_fugir);
                        if(escolha_dado_fugir ==1){
					       srand(time(0));
						   dado =(1+rand()%10); 
						   
    				    }
				    }
					printf("\nVoce tirou: %d\n", dado);
					if(dado >= 8){
						printf("Voce conseguiu fugir");
					}else if(dado >1 && dado <8){
						printf("Voce nao conseguiu fugir e tera que lutar pela sua propria vida!");
						while(escolha_dado !=1){
						    while(hp_lider_ork != 0 || hp != 0){
							    printf("\nDigite 1 para rolar o dado e tentar atacar!\n");
							    scanf("%d",&escolha_dado);
		                        if(escolha_dado == 1){
								    
								    
									dado = (1+rand()%10);
									printf("Voce tirou: %d\n",dado);
									/*Se o jogador tirar 6 a 9 - Ele acerta*/
									if(dado>=6 && dado<10){
									    dano_causado=forca*2;
									    hp_lider_ork=hp_lider_ork-dano_causado;
                                        printf("Causou %d de dano",dano_causado);
                                        printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
                                        if(hp_lider_ork <=0){
									        printf("\nVOCE MATOU O LIDER ORK!");
									        exit(0);
									    }
                                        printf("\nO Lider Ork irá atacar!");
                                        dado=0;
                                        
									    dado = (1+rand()%10);
									    printf("\nO Lider Ork tirou: %d\n",dado);
									    
									    if(dado>=6 && dado<10){
									       dano_causado=hp_att/2;
									        hp=hp-dano_causado;
									        printf("O Lider Ork causou %d de dano",dano_causado);
									        printf("\nSua vida atual é: %d",hp);
									        if(hp <=0){
									            printf("\nVoce morreu...");
									            exit(0);
									        }
									    }else if(dado == 10){
									        printf("O Lider Ork acertou no seu coracao e voce morreu...");
									        exit(0);
									        
									    }else if(dado <= 5){
									        printf("Voce conseguiu desviar!");
									    }else if(dado == 1){
									        printf("Na tentativa de ataque, o Lider Ork escorregou e caiu.");
									        dano_causado = forca*3;
									        hp_lider_ork=hp_lider_ork-dano_causado;
									        printf("\nVoce atacou e causou %d",dano_causado);
									        printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
									        if(hp_lider_ork <=0){
									            printf("\nVOCE MATOU O LIDER ORK!");
									            exit(0);
									        }
									        
									    }  
									}/*Se o jogador tirar 10, ele tem um acerto critico*/
									else if(dado == 10){
									    printf("Voce perfurou o Lider Ork!");
									    dano_causado=forca*4;
									    hp_lider_ork=hp_lider_ork-dano_causado;
									    printf("\nVoce causou: %d",dano_causado);
									    printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
									    if(hp_lider_ork <=0){
									       printf("\nVOCE MATOU O LIDER ORK!");
									       exit(0);
									   }
									    printf("\nO Lider Ork irá atacar!");
                                        dado=0;
                                        
									    dado = (1+rand()%10);
									    printf("\nO Lider Ork tirou: %d\n",dado);
									    
									    if(dado>=6 && dado<10){
									       dano_causado=hp_att/2;
									        hp=hp-dano_causado;
									        printf("O Lider Ork causou %d de dano",dano_causado);
									        printf("\nSua vida atual é: %d",hp);
									        if(hp <=0){
									            printf("\nVoce morreu...");
									            exit(0);
									        }
									    }else if(dado == 10){
									        printf("O Lider Ork acertou no seu coracao e voce morreu...");
									        exit(0);
									        
									    }else if(dado <= 5){
									        printf("Voce conseguiu desviar!");
									    }else if(dado == 1){
									        printf("Na tentativa de ataque, o Lider Ork escorregou e caiu.");
									        dano_causado = forca*3;
									        hp_lider_ork=hp_lider_ork-dano_causado;
									        printf("\nVoce atacou e causou %d",dano_causado);
									        printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
									        if(hp_lider_ork <=0){
									            printf("\nVOCE MATOU O LIDER ORK!");
									            exit(0);
									        }
									    }
								    }/*Se o jogador tirar 5 a 2, ele erra*/
									else if(dado <= 5 && dado >1){
									    printf("Na tentativa de ataque, o Lider ork desviou e riu de voce!\n");
									    printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
                                        printf("\nO Lider Ork irá atacar!");
                                        
                                        dado=0;
									    dado = (1+rand()%10);
									    
									    printf("\nO Lider Ork tirou: %d\n",dado);
									    if(dado>=6 && dado<10){
									       dano_causado=hp_att/2;
									        hp=hp-dano_causado;
									        printf("O Lider Ork causou %d de dano",dano_causado);
									        printf("\nSua vida atual é: %d",hp);
									        if(hp <=0){
									            printf("\nVoce morreu...");
									            exit(0);
									        }
									    }else if(dado == 10){
									        printf("O Lider Ork acertou no seu coracao e voce morreu...");
									        exit(0);
									        
									    }else if(dado <= 5){
									        printf("Voce conseguiu desviar!");
									    }else if(dado == 1){
									        printf("Na tentativa de ataque, o Lider Ork escorregou e caiu;");
									        dano_causado = forca*3;
									        hp_lider_ork=hp_lider_ork-dano_causado;
									        printf("\nVoce atacou e causou %d",dano_causado);
									        printf("\nVida atual do Lider Ork: %d",hp_lider_ork);
									        if(hp_lider_ork <=0){
									            printf("\nVOCE MATOU O LIDER ORK!");
									            exit(0);
									        }
									    }
                                    }/*Se o jogador tirar 1, ele tem um erro critico e o Monstro ataca direto*/
									else if(dado == 1){
									    printf("Na hora de tentar atacar, o Lider ork desviou e lhe deu um chute!\n");
									    dano_causado = hp_att/2 + 1;
									    hp=hp-dano_causado;
									    printf("O Lider Ork causou %d de dano",dano_causado);
									    if(hp <=0){
									       printf("\nVoce morreu...");
									       exit(0);
									    }
									}
									hp=hp;
									dado =1;
									hp_lider_ork=hp_lider_ork;
								}
							}
						}
		
					}else if(dado ==1){
						printf("Voce se atrapalhou na hora de fugir, caiu no chao e o lider ork correu para cima de voce!\n");
						printf("\nEle crava a espada no seu coração!");
						printf("\nVoce morreu...");
						exit(0);
                        
					}
				}
			}
		}else{
			printf("Escolha um caminho existente!\n");
		}
	
	}

	

	
}


int main(int argc, char *argv[]) {

	menu();
	
	
	return 0;
}
