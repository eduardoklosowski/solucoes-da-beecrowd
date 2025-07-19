defmodule Mapa do
  use Agent

  def start_link() do
    Agent.start_link(fn -> %{} end, name: __MODULE__)
  end

  def get(i, j) do
    Agent.get(__MODULE__, & Map.get(Map.get(&1, i), j))
  end

  def set(i, j, k) do
    Agent.update(__MODULE__, & Map.update(&1, i, %{j => k}, fn mapa -> Map.put(mapa, j, k) end))
  end
end

defmodule Modulo do
  def floodAndFill(i, j) do
    if ((i > 0) && (i < 6) && (j > 0) && (j < 6)) do
      if (Mapa.get(i, j) == 0) do
        Mapa.set(i, j, 2)
        floodAndFill(i - 1, j)
        floodAndFill(i + 1, j)
        floodAndFill(i, j - 1)
        floodAndFill(i, j + 1)
      end
    end
  end

  def primeiraLinha(linha) do
    if linha == "" do
      nova_linha = IO.gets("") |> String.trim
      primeiraLinha(nova_linha)
    else
      linha
    end
  end

  def processa(n) do
    if n > 0 do
      Mapa.start_link()
      linha = primeiraLinha("") |> String.split(" ") |> Enum.map(fn n -> String.to_integer(n) end)
      for j <- 1..5 do
        Mapa.set(1, j, Enum.at(linha, j - 1))
      end

      for i <- 2..5 do
        linha = IO.gets("") |> String.trim |> String.split(" ") |> Enum.map(fn n -> String.to_integer(n) end)
        for j <- 1..5 do
          Mapa.set(i, j, Enum.at(linha, j - 1))
        end
      end

      floodAndFill(1, 1)

      if (Mapa.get(5, 5) == 2) do
        IO.puts("COPS")
      else
        IO.puts("ROBBERS")
      end

      processa(n - 1)
    end
  end
end

n = IO.gets("") |> String.trim |> String.to_integer
Modulo.processa(n)