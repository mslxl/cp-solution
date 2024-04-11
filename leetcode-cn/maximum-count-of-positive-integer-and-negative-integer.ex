defmodule Solution do
  @spec maximum_count(nums :: [integer]) :: integer
  def maximum_count(nums) do
    max(Enum.filter(nums, &(&1 > 0))
    |> Enum.count, Enum.filter(nums, &(&1 < 0))
    |> Enum.count)
  end
end
