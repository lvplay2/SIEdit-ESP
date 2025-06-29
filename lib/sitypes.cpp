#include "sitypes.h"

#include "util.h"

namespace si {

const char *MxOb::GetTypeName(Type type)
{
  switch (type) {
  case Video:
    return "SMK";
  case Sound:
    return "WAV";
  case Presenter:
    return "MxPresenter";
  case Bitmap:
    return "BMP";
  case Object:
    return "Objeto 3D";
  case World:
    return "Mundo";
  case Event:
    return "Evento";
  case Animation:
    return "Animación";
  case Null:
  case TYPE_COUNT:
    break;
  }

  return "Desconocido";
}

std::vector<const char*> MxOb::GetFlagsName(Flags flags)
{
  std::vector<const char*> names;

  if (flags == FLAGS_COUNT) {
    return names;
  }

  if (flags & Transparent) {
    names.push_back("Transparent");
  }
  if (flags & NoLoop) {
    names.push_back("NoLoop");
  }
  if (flags & LoopCache) {
    names.push_back("LoopCache");
  }
  if (flags & LoopStream) {
    names.push_back("LoopStream");
  }
  if (flags & Unknown) {
    names.push_back("Unknown");
  }

  return names;
}

const char *RIFF::GetTypeDescription(Type t)
{
  switch (t) {
  case RIFF_:
    return "Resource Interchange File Format";
  case LIST:
    return "Lista de sub-elementos";
  case MxSt:
    return "Stream";
  case MxHd:
    return "Encabezado de intercalado";
  case MxCh:
    return "Chunk de datos";
  case MxOf:
    return "Tabla de Offset";
  case pad_:
    return "Relleno";
  case MxOb:
    return "Objeto transmitible";
  case MxDa:
    return "Datos";
  case WAVE:
    return "WAVE";
  case fmt_:
    return "Formato WAVE";
  case OMNI:
    return "OMNI";
  case data:
    return "Datos WAVE";
  }

  return "Desconocido";
}

RIFF::Chk RIFF::BeginChunk(FileBase *f, uint32_t type)
{
  Chk stat;

  f->WriteU32(type);
  stat.size_position = f->pos();
  f->WriteU32(0);
  stat.data_start = f->pos();

  return stat;
}

void RIFF::EndChunk(FileBase *f, const Chk &stat)
{
  size_t now = f->pos();

  uint32_t sz = now - stat.data_start;

  f->seek(stat.size_position);
  f->WriteU32(sz);

  f->seek(now);

  if (sz%2 == 1) {
    f->WriteU8(0);
  }
}

}
