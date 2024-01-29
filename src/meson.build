puzzle15_sources = [
  'main.c',
  'puzzle15-window.c',
  'puzzle15-application.c',
]

puzzle15_deps = [
  dependency('libadwaita-1', version: '>= 1.0'),
]

gnome = import('gnome')

puzzle15_sources += gnome.compile_resources('puzzle15-resources',
  'puzzle15.gresource.xml',
  c_name: 'puzzle15'
)

executable('puzzle15', puzzle15_sources,
  dependencies: puzzle15_deps,
  install: true,
)
