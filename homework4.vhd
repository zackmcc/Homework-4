-- ECE532 HW4
-- Zackary McClamma
-- 28-Oct-2019

library ieee;
  use ieee.std_logic_1164.all;

entity homework4 is
  port
  (
			i_clk         : in  std_logic := 'X'; -- clk
			i_reset_n     : in  std_logic := 'X'; -- reset_n
         i_uart_rxd      : in  std_logic := 'X'; -- rxd
         o_uart_txd      : out std_logic         -- txd			

 
  );
end homework4;

architecture sch of homework4 is

  component hw4_cpu is
	port (
            clk_clk           : in  std_logic := 'X'; -- clk
            reset_reset_n     : in  std_logic := 'X'; -- reset_n
				uart_rxd	: in  std_logic := 'X';
				uart_txd    : out std_logic

        );
  end component hw4_cpu;
  
begin

    u0 : component hw4_cpu
        port map (
            clk_clk           => i_clk,           --        clk.clk
            reset_reset_n     => i_reset_n,     --      reset.reset_n
				uart_rxd    => i_uart_rxd,
				uart_txd   => o_uart_txd

        );
end sch;
