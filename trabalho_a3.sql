--criação da tabela cliente
CREATE TABLE tb_cliente
(
	clienteID INTEGER     NOT NULL,
	RG        VARCHAR(15) NOT NULL,
	CPF       VARCHAR(15) NOT NULL,
	nome      VARCHAR(50) NOT NULL,
	dataNas   VARCHAR(10) NOT NULL,
	telefone1 VARCHAR(14),
	telefone2 VARCHAR(14),
	email     VARCHAR(50),
	CONSTRAINT tb_cliente_pk_clienteID PRIMARY KEY (clienteID)
);
--comentários da tabela cliente
COMMENT ON TABLE tb_cliente IS 'Tabela para armazenamento de dados do cliente';
--comentários das colunas da tabela cliente
COMMENT ON COLUMN tb_cliente.clienteID IS 'numero identificador do cliente(chave primária)	    ';
COMMENT ON COLUMN tb_cliente.RG        IS 'tupla para armazenamento de RG do cliente      	    ';
COMMENT ON COLUMN tb_cliente.CPF       IS 'tupla para armazenamento do Cpf do cliente     	    ';
COMMENT ON COLUMN tb_cliente.nome      IS 'tupla para armazenamento do nome cliente                 ';
COMMENT ON COLUMN tb_cliente.dataNas   IS 'tupla que irá armazenar a data de nascimento do cliente  ';
COMMENT ON COLUMN tb_cliente.telefone1 IS 'tupla para armazenamento do contato do cliente           ';
COMMENT ON COLUMN tb_cliente.telefone2 IS 'tupla para armazenamento do contato secundário do cliente';
COMMENT ON COLUMN tb_cliente.email     IS 'tupla para armazenamento do email do cliente             ';

--criação da tabela carro
CREATE TABLE tb_carro
(
	carroID    INTEGER     NOT NULL,
	nome       VARCHAR(50) NOT NULL,
	ano 	   INTEGER     NOT NULL,
	marca      VARCHAR(50) NOT NULL,
	tipo       VARCHAR(50),
	CONSTRAINT tb_carro_pk_carroID PRIMARY KEY (carroID)
);
--comentários da tabela carro
COMMENT ON TABLE tb_carro IS 'tabela para armazenamento dos dados de carro';
--comentários das colunas da tabela carro
COMMENT ON COLUMN tb_carro.carroID IS 'tupla para armazenamento do número identificador de carro(primary key)';
COMMENT ON COLUMN tb_carro.nome    IS 'tupla para armazenamento do nome do carro(Golf, Gallardo)             ';
COMMENT ON COLUMN tb_carro.ano     IS 'tupla para armazenamento do ano do carro(ano:2010)                    ';
COMMENT ON COLUMN tb_carro.marca   IS 'tupla para armazenamento da marca do carro (Ford, Lamborghini)        ';
COMMENT ON COLUMN tb_carro.tipo    IS 'tupla para armazenamento do tipo de carro (passeio, caminhonete, luxo)';

--criação da tabela compra
CREATE TABLE tb_compra
(
	compraID        INTEGER      NOT NULL,
	forma_pagamento VARCHAR(50)  NOT NULL,
	valor_total     DECIMAL      NOT NULL,
	clienteID       INTEGER      NOT NULL REFERENCES tb_cliente(clienteID),
	carroID         INTEGER      NOT NULL REFERENCES tb_carro(carroID),
	CONSTRAINT tb_compra_pk_compraID PRIMARY KEY(compraID)
);
--comentários da tabela compra
COMMENT ON TABLE tb_compra IS 'tabela compra com os dados de cliente, o carro comprado, valores e formas de pagamento';
--comentários das colunas da tabela compra
COMMENT ON COLUMN tb_compra.compraID     IS 'tupla que ira armazenar o numero identificador da compra(primary key)';
COMMENT ON COLUMN tb_compra.forma_pagamento IS 'tupla que ira armazenar a forma de pagamento escolhida pelo cliente  ';
COMMENT ON COLUMN tb_compra.valor_total  IS 'tupla que ira armazenar o valor total da compra			  ';
COMMENT ON COLUMN tb_compra.clienteID    IS 'tupla que ira armazenar os dados do cliente		          ';
COMMENT ON COLUMN tb_compra.carroID 	 IS 'tupla que ira armazenar os dados do carro				  ';

--criação das sequences
--criação da sequence para a tabela cliente
CREATE SEQUENCE tb_cliente_seq
	INCREMENT 1
	MINVALUE  1
	MAXVALUE  9223372036854775807
	START     1
	CACHE     1;

--criação da sequence para a tabel a carro
CREATE SEQUENCE tb_carro_seq
	INCREMENT 1
	MINVALUE  1
	MAXVALUE  9223372036854775807
	START     1
	CACHE     1;

--criação da sequence para a tabela compra
CREATE SEQUENCE tb_compra_seq
	INCREMENT 1
	MINVALUE  1
	MAXVALUE  9223372036854775807
	START     1
	CACHE     1;
