#ifndef WAVEFORMMARK_H
#define WAVEFORMMARK_H

#include <QDomNode>
#include <QImage>

#include "util/memory.h"

#include "waveform/renderers/waveformmarkproperties.h"

class ControlProxy;
class SkinContext;
class WaveformSignalColors;

class WaveformMark {
  public:
    void setup(const QString& group, const QDomNode& node,
               const SkinContext& context,
               const WaveformSignalColors& signalColors);

    std::unique_ptr<ControlProxy> m_pPointCos;

    const WaveformMarkProperties& properties() const;
    void setProperties(const WaveformMarkProperties& properties);

  private:
    WaveformMarkProperties m_properties;
    QImage m_image;

    friend class WaveformRenderMark;
};

#endif // WAVEFORMMARK_H
