[CmdletBinding()]
Param([int]$MaxTestcaseNumber,
  [string]$Dataset,
  [string]$Standard,
  [string]$Test)

For ($testcase = 1; $testcase -le $MaxTestcaseNumber; $testcase++)
{
  Write-Output "Testcase ${testcase}:"
  $TestData = ""
  if($Dataset -eq "id")
  {
    $TestData = $testcase.ToString()
  } else
  {
    $TestData = (Start-Process $Dataset)
  }
  $STD = (Start-Process -FilePath $Standard $TestData) -join "`n"
  $TEST = (Start-Process -FilePath $Test $TestData) -join "`n"
  $STD = $STD.ToString().Trim()
  $TEST = $TEST.ToString().Trim()

  if($STD -eq $Test)
  {
    Write-Output "Pass"
  } else
  {
    Write-Output "Fail with input:"
    Write-Output $TestData
    Write-Output $TestData > faildata.txt
  }

}


