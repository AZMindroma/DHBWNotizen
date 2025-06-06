import nbclean as nbc


def clean_notebook(source, target):
	ntbk = nbc.NotebookCleaner(source)

	# Remove output
	ntbk.clear(kind="output")

	# Replacing text
	text_replace_begin = '### SOLUTION BEGIN'
	text_replace_end = '### SOLUTION END'
	ntbk.replace_text(text_replace_begin, text_replace_end)

	ntbk.save(target)

def clean_notebook_collection():
	#ntbks = ["TestNotebook"]
	ntbks = ["SciProLab_1_Basics", "SciProLab_2_Stochastik", "SciProLab_3_Bruchzahlen", "SciProLab_4_Vektoren", "SciProLab_5_Matrizen", "SciProLab_6_Vererbung", "SciProLab_7_Funktionen"]
	cleaning_suffix = "cleaned"
	for ntbk in ntbks:
		src = f'{ntbk}.ipynb'
		target = f'{ntbk}_{cleaning_suffix}.ipynb'
		print(f'Clean {src} -> {target}')
		clean_notebook(src,target)
	
if __name__ == '__main__':
	clean_notebook_collection()

