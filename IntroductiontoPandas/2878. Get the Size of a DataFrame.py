import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    a = []
    rows, cols = players.shape
    a.extend([rows, cols])
    return a

# OR

import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    rows, cols = players.shape
    return [rows, cols]

# OR

import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)