
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity text_on_segment is
    Port ( seg : out  STD_LOGIC_VECTOR (6 downto 0);	-- Segment 0-6 
           an : out  STD_LOGIC_VECTOR (3 downto 0);	-- Anoda 0-3
           mclk : in  STD_LOGIC);
end text_on_segment;

architecture Behavioral of text_on_segment is
signal ce:STD_LOGIC;
signal temp:STD_LOGIC_VECTOR (1 downto 0);				-- Temporary 0-1
begin

Inst_counters_1: entity counters_1 PORT MAP(				-- Vytvoreni entity counters_1
			CLK => mclk,											--clock
			CE => ce,				
			Q => temp												--temporary
	);
Inst_puls: entity puls PORT MAP(								-- Vytvoreni entity puls
			clk => mclk,											--clock2
			pulse => ce												--puls
	);
			with temp Select
   seg<= "0000110" when "00",   -- Aktivace posledniho E na sedmisegmentu
         "0010010" when "01",   -- Aktivace predposledniho S na sedmisegmentu
         "0001100" when "10",   -- Aktivace druheho P na sedmisegmentu
         "0010010" when "11",   -- Aktivace prvniho S na sedmisegmentu
         
         "1111111" when others;   
			
			 with temp Select
   an<=  "1110" when "00",   -- NULA
         "1101" when "01",   -- JEDNA
         "1011" when "10",   -- DVA 
         "0111" when "11",   -- TRI
         
         "1111" when others;  --ZBYTEK
end Behavioral;

