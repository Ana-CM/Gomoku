 for ( int i = 0; i < num; i++ ) { // verificando se houve vitoria por linha ou coluna
			    
                if( ( 0 != tabuleiro[0][num] ) && ( tabuleiro[0][num] == tabuleiro[1][num] ) && ( tabuleiro[1][num] == tabuleiro[2][num] ) &&  ( tabuleiro[2][num] == tabuleiro[3][num] ) ) {
                    final = true;

                    if ( 1 == tabuleiro[0][num] ) {
                        resultado = " Vitoria do jogador 1, ganhou por coluna";
                    } else {
                        resultado = " Vitoria do jogador 2, ganhou por coluna";
                    }

                }

                if ( ( 0 != tabuleiro[num][0] ) && ( tabuleiro[num][0] == tabuleiro[num][1] ) && ( tabuleiro[num][1] == tabuleiro[num][2] ) && ( tabuleiro[num][2] == tabuleiro[num][3] ) ) {
                    final = true;

                    if ( 1 == tabuleiro[num][0] ) {
                        resultado = " Vitoria do jogador 1, ganhou por linha";
                    } else {
                        resultado = " Vitoria do jogador 2, ganhou por linha";
                    }
                }

                if ( final ) {
                    break;
                }
            }

            if ( ! final ) { // verificando se houve vitoria por diagonal
                if( ( 0 != tabuleiro[0][0] ) && ( tabuleiro[0][0] == tabuleiro[1][1] ) && ( tabuleiro[1][1] == tabuleiro[2][2] )  && ( tabuleiro[2][2] == tabuleiro[3][3] ) ) {
                    final = true;

                    if ( 1 == tabuleiro[0][0] ) {
                        resultado = " Vitoria do jogador 1, ganhou por diagonal principal";
                    } else {
                        resultado = " Vitoria do jogador 2, ganhou por diagonal principal";
                    }
                } else if ( ( 0 != tabuleiro[0][3] ) && ( tabuleiro[0][3] == tabuleiro[1][2] ) && ( tabuleiro[1][2] == tabuleiro[2][1] ) && ( tabuleiro[2][1] == tabuleiro[3][0] ) ) {
                    final = true;

                    if ( 1 == tabuleiro[0][3] ) {
                        resultado = " Vitoria do jogador 1, ganhou por diagonal secundaria";
                    } else {
                        resultado = " Vitoria do jogador 2, ganhou por diagonal secundaria";
                    }
                }
            }

            vazio = false;

            if ( ! final ) { // verificando se houve empate
                
                for( int i = 0; i < num; i++ ) {
                    for( int j = 0; j < num; j++ ) {
                        if( 0 == tabuleiro[i][j] ) {
                            vazio = true;
                            break;
                        }
                    }
                    
                }

                if( ! vazio ) {
                    final = true;
                    resultado = "Empate";
                }
            }
        }
    }
