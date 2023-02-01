
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity counters_1 is
    port(CLK, CE : in std_logic;
         Q : out std_logic_vector(1 downto 0));
end counters_1;

architecture archi of counters_1 is
    signal tmp: std_logic_vector(1 downto 0);
begin
    process (CLK)
    begin
        if (CLK'event and CLK='1') then
          if (CE='1') then
            
				tmp <= tmp + 1;
          end if;
        end if;
    end process;

    Q <= tmp;

end archi;
