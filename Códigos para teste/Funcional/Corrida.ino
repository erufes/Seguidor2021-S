////////////// Funçoes auxiliares //////////////
void EstadoMovimento(int direcao, int velE, int velD);
void lerLinha();

////////////// Movimentacao do carro //////////////
void EstadoMovimento(int direcao, int velE, int velD){
    switch(direcao){ // Motor esquerdo
        case 1: //reto
            digitalWrite(motorEsq[0], HIGH);
            digitalWrite(motorEsq[1], LOW);
            analogWrite(motorEsq[2], velE);
            break;
        case 2:  //direita
            digitalWrite(motorEsq[0], HIGH);
            digitalWrite(motorEsq[1], LOW);
            analogWrite(motorEsq[2], velE);
            break;
        case 3:  // esquerda
            digitalWrite(motorEsq[0], HIGH);
            digitalWrite(motorEsq[1], LOW);
            analogWrite(motorEsq[2], velE);
            break;
        case 4:  // parado
            digitalWrite(motorEsq[0], LOW);
            digitalWrite(motorEsq[1], LOW);
            analogWrite(motorEsq[2], velE);
            break;
        case 5:  //re
            digitalWrite(motorEsq[0], LOW);
            digitalWrite(motorEsq[1], HIGH);
            analogWrite(motorEsq[2], velE);
        break;
    }
     switch(direcao){  // Motor direito
        case 1: //  reto
            digitalWrite(motorDir[0], HIGH);
            digitalWrite(motorDir[1], LOW);
            analogWrite(motorDir[2], velD);
            break;
        case 2: // direita
            digitalWrite(motorDir[0], HIGH);
            digitalWrite(motorDir[1], LOW);
            analogWrite(motorDir2], velD);
            break;
        case 3:  // esquerdo
            digitalWrite(motorDir[0], HIGH);
            digitalWrite(motorDir[1], LOW);
            analogWrite(motorDir[2], velD);
            break;
        case 4: // parado
            digitalWrite(motorDir[0], LOW);
            digitalWrite(motorDir[1], LOW);
            analogWrite(motorDir[2], velD);
            break;
        case 5:  // re
            digitalWrite(motorDir[0], LOW);
            digitalWrite(motorDir[1], HIGH);
            analogWrite(motorDir[2], velD);
            break;
    }
}

void lerLinha(){

}