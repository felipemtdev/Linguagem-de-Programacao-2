alert('Olá, seja bem-vindo ao curso!!!');

// Exemplo de Tipos de Dados
var variavel = 1; // inteiro
console.log(typeof variavel);

var variavel = "1"; // String
console.log(typeof variavel);

var variavel = true; // Booleano
console.log(typeof variavel);

// Manipulação de Elementos no HTML
document.getElementById('texto').value = 'Tudo bem?';

// Métodos de String
var texto = "O javascript torna as páginas web mais interativas";
document.write(texto);
document.write("<br>");
document.write(texto.toLowerCase());
document.write("<br>");
document.write(texto.toUpperCase());
document.write("<br><br>");

// Entradas do Usuário
var nome = prompt('Digite seu nome:');
var idade = prompt('Digite sua idade:');

console.log(typeof idade);

var ano = 2026 - parseInt(idade);

console.log(typeof parseInt(idade));
console.log(typeof parseFloat(idade));

document.write('<h1> Seu nome é ' + nome + ', tem ' + idade + ' anos e nasceu em ' + ano + '</h1>');

// Arrays
var lista_produtos = Array('Camiseta', 'Jaqueta', 'Moleton', 'Calça');
var lista_frutas = [];

lista_frutas[0] = 'Banana';
lista_frutas[1] = 'Maçã';
lista_frutas[2] = 'Morango';
lista_frutas[3] = 'Uva';

console.log(lista_frutas);
console.log(lista_produtos);
