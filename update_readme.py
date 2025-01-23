import os

def detect_languages():
    languages = set()
    for root, _, files in os.walk('.'):
        for file in files:
            if file.endswith('.py'):
                languages.add('Python')
            elif file.endswith('.js'):
                languages.add('JavaScript')
            # Add more file extensions and corresponding languages as needed
    return languages

def update_readme(languages):
    readme_path = 'README.md'
    with open(readme_path, 'r') as file:
        lines = file.readlines()

    with open(readme_path, 'w') as file:
        in_languages_section = False
        for line in lines:
            if line.startswith('## Languages Used'):
                in_languages_section = True
                file.write('## Languages Used\n')
                for language in languages:
                    file.write(f'- {language}\n')
            elif in_languages_section and line.startswith('## '):
                in_languages_section = False
                file.write(line)
            elif not in_languages_section:
                file.write(line)

if __name__ == '__main__':
    languages = detect_languages()
    update_readme(languages)
