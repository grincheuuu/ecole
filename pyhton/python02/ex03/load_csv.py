import pandas as pd


def load(path: str) -> pd.DataFrame:
    """chargement fichier csv avec pandas"""
    try:
        filee = pd.read_csv(path)
    except FileNotFoundError:
        print("FileNotFoundError: the path is bad")
        return None
    except pd.errors.ParserError:
        print("ParserError: bad format")
        return None
    except UnicodeDecodeError:
        print("UnicodeDecodeError")
    except PermissionError:
        print("PermissionError")
    except Exception as e:
        print(f"innatendue error: {e}")
#    print(f"Loading dataset of dimensions {file.shape}")
    return filee
